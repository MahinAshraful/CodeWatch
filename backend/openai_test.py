import os
import numpy as np
from sklearn.metrics.pairwise import cosine_similarity
from dotenv import load_dotenv
from transformers import AutoModel, AutoTokenizer
import torch
import openai
import time

load_dotenv()

# setting up openai
openai.api_key = os.getenv("OPENAI_API_KEY")
client = openai.OpenAI(api_key=os.getenv("OPENAI_API_KEY"))

# setting up CodeT5+ for code embeddings
device = "cuda" if torch.cuda.is_available() else "cpu"
checkpoint = "Salesforce/codet5p-110m-embedding"
tokenizer = AutoTokenizer.from_pretrained(checkpoint, trust_remote_code=True)
model = AutoModel.from_pretrained(checkpoint, trust_remote_code=True).to(device)


def get_code_embedding(code):
    """Get code embeddings using CodeT5+."""
    try:
        inputs = tokenizer.encode(code, return_tensors="pt").to(device)
        # input length issues
        if inputs.shape[1] > 512:
            inputs = inputs[:, :512]
        with torch.no_grad():
            embedding = model(inputs)[0]
        return embedding.cpu().numpy()
    except Exception as e:
        print(f"Error getting embedding: {e}")
        return None


def rewrite_code(code, retry_attempts=3, retry_delay=60):
    """Have GPT rewrite the given code snippet with retry logic."""
    prompt = f"""
    ### Code:
    {code}
    ### Instruction:
    Please explain the functionality of the given code, then rewrite it in a single markdown code block. First find out what the code is doing and what is for, and then rewrite it from scratch. No additional clarifications.
    
    Format your response following this structure exactly:
    
    1. Brief explanation of what the code does
    2. A code block with your rewrite, using the ``` and ``` format
    3. Any other important part of the code like test cases etc
    
    Important: Provide ONLY the explanation and code block. Do not add ANY other text.
    """

    for attempt in range(retry_attempts):
        try:
            response = client.chat.completions.create(
                model="gpt-4o-mini",
                messages=[
                    {
                        "role": "system",
                        "content": "You are a helpful assistant that rewrites code in the way you would do it. Return only the explanation and code block with no additional text.",
                    },
                    {"role": "user", "content": prompt},
                ],
            )

            content = response.choices[0].message.content

            # Extract code block from response
            if "```" in content:
                parts = content.split("```")
                if len(parts) >= 3:
                    rewritten_code = parts[1]
                    # Remove language identifier if present
                    if (
                        rewritten_code.split("\n", 1)[0].strip()
                        and not rewritten_code.split("\n", 1)[0]
                        .strip()
                        .startswith("import")
                        and not rewritten_code.split("\n", 1)[0]
                        .strip()
                        .startswith("def")
                    ):
                        rewritten_code = (
                            rewritten_code.split("\n", 1)[1]
                            if len(rewritten_code.split("\n", 1)) > 1
                            else rewritten_code
                        )
                    return rewritten_code.strip()
            return content

        except openai.RateLimitError as e:
            if attempt < retry_attempts - 1:
                print(f"Rate limit hit, waiting {retry_delay} seconds before retry...")
                time.sleep(retry_delay)
            else:
                print(f"All retry attempts failed: {e}")
                return code  # Return original code as fallback
        except Exception as e:
            print(f"Error rewriting code: {e}")
            return code  # Return original code as fallback


def extract_problem_statement(code, retry_attempts=3, retry_delay=60):
    """Extract the problem statement/task that the code is solving using GPT"""
    prompt = f"""
    ### Code:
    {code}
    
    ### Instruction:
    Analyze the given code and extract the exact programming problem or task it's solving.
    
    Format your response as a clear, detailed programming challenge that precisely describes what the code accomplishes.
    Your description should include:
    - Input format and requirements
    - Expected output and requirements
    - Any constraints or edge cases
    - Any other important part of the code like test cases etc
    
    Important: 
    1. Be specific about what problem the code solves, not how it solves it
    2. Provide enough detail that someone could implement the solution without seeing the original code
    3. Return ONLY the problem statement with no additional text
    4. Remember your explanation is a prompt to try to REPLICATE this code by giving your output as a prompt to AI
    """

    for attempt in range(retry_attempts):
        try:
            response = client.chat.completions.create(
                model="gpt-4o-mini",
                messages=[
                    {
                        "role": "system",
                        "content": "You are a skilled programming instructor who creates precise problem statements from code samples. Return only the problem statement with no additional text.",
                    },
                    {"role": "user", "content": prompt},
                ],
            )

            problem_statement = response.choices[0].message.content
            print(f"Extracted problem statement: {problem_statement}\n")
            return problem_statement

        except openai.RateLimitError as e:
            if attempt < retry_attempts - 1:
                print(f"Rate limit hit, waiting {retry_delay} seconds before retry...")
                time.sleep(retry_delay)
            else:
                print(f"All retry attempts failed: {e}")
                return "Could not extract problem statement"
        except Exception as e:
            print(f"Error extracting problem statement: {e}")
            return "Could not extract problem statement"


def generate_code_from_problem(problem_statement, retry_attempts=3, retry_delay=60):
    """Generate code from the extracted problem statement using GPT"""
    prompt = f"""
    ### Programming Problem:
    {problem_statement}
    
    ### Instruction:
    Write code to solve this problem. Your solution should be:
    - Efficient
    - Well-structured
    - Correctly handling all requirements and edge cases
    
    Return ONLY the code solution in a single markdown code block using ``` and ``` format.
    Do not include any explanations, comments, or additional text outside the code block.
    """

    for attempt in range(retry_attempts):
        try:
            response = client.chat.completions.create(
                model="gpt-4o-mini",
                messages=[
                    {
                        "role": "system",
                        "content": "You are an coding assistant write the best possible code",
                    },
                    {"role": "user", "content": prompt},
                ],
            )

            content = response.choices[0].message.content

            # Extract code block from response
            if "```" in content:
                parts = content.split("```")
                if len(parts) >= 3:
                    generated_code = parts[1]
                    # Remove language identifier if present
                    if (
                        generated_code.split("\n", 1)[0].strip()
                        and not generated_code.split("\n", 1)[0]
                        .strip()
                        .startswith("import")
                        and not generated_code.split("\n", 1)[0]
                        .strip()
                        .startswith("def")
                    ):
                        generated_code = (
                            generated_code.split("\n", 1)[1]
                            if len(generated_code.split("\n", 1)) > 1
                            else generated_code
                        )
                    return generated_code.strip()
            return content

        except openai.RateLimitError as e:
            if attempt < retry_attempts - 1:
                print(f"Rate limit hit, waiting {retry_delay} seconds before retry...")
                time.sleep(retry_delay)
            else:
                print(f"All retry attempts failed: {e}")
                return "Could not generate code"
        except Exception as e:
            print(f"Error generating code: {e}")
            return "Could not generate code"


def detect_ai_generated(code, num_rewrites=3, min_rewrites=1):
    """Detect if code is AI-generated based on rewrite similarity."""
    print("Generating rewrites...")
    rewrites = []

    for i in range(num_rewrites):
        try:
            rewrite = rewrite_code(code)
            if rewrite and rewrite != code:  # Only add if rewrite was successful
                rewrites.append(rewrite)
                print(f"Rewrite {len(rewrites)} complete")
            else:
                print(f"Rewrite {i+1} failed, using original as fallback")
        except Exception as e:
            print(f"Error during rewrite {i+1}: {e}")

    # Check if we have enough rewrites to make a meaningful calculation
    if len(rewrites) < min_rewrites:
        print(
            f"Warning: Only {len(rewrites)} successful rewrites. Results may be unreliable."
        )

    if len(rewrites) == 0:
        print("Cannot calculate similarity without rewrites.")
        return None

    print("Getting embeddings...")
    original_embedding = get_code_embedding(code)
    if original_embedding is None:
        print("Failed to get embedding for original code.")
        return None

    # Get embeddings for successful rewrites
    similarities = []
    for i, rewrite in enumerate(rewrites):
        emb = get_code_embedding(rewrite)
        if emb is not None:
            similarity = cosine_similarity([original_embedding], [emb])[0][0]
            similarities.append(similarity)
            print(f"Similarity for rewrite {i+1}: {similarity:.4f}")
        else:
            print(f"Failed to get embedding for rewrite {i+1}")

    if not similarities:
        print("No similarity scores could be calculated.")
        return None

    # Average similarity score from available results
    avg_similarity = sum(similarities) / len(similarities)
    print(
        f"Average similarity score (from {len(similarities)} rewrites): {avg_similarity:.4f}"
    )

    return avg_similarity


def detect_ai_generated_enhanced(code, num_rewrites=3, min_rewrites=1):
    """Enhanced detection comparing similarities between original code and AI-generated code."""
    print("====== STEP 1: Extracting Problem Statement ======")
    problem_statement = extract_problem_statement(code)

    print("\n====== STEP 2: Generating New Code from Problem Statement ======")
    ai_generated_code = generate_code_from_problem(problem_statement)
    print("\nAI-generated code from problem statement:")
    print("```")
    print(ai_generated_code)
    print("```")

    print("\n====== STEP 3: Testing Original Code ======")
    original_similarity = detect_ai_generated(code, num_rewrites, min_rewrites)

    print("\n====== STEP 4: Testing AI-Generated Code ======")
    ai_similarity = detect_ai_generated(ai_generated_code, num_rewrites, min_rewrites)

    # Compare the similarities
    if original_similarity is None or ai_similarity is None:
        return "Could not determine if code is AI-generated due to calculation errors."

    similarity_diff = abs(original_similarity - ai_similarity)

    print("\n====== COMPARISON RESULTS ======")
    print(f"Original code similarity: {original_similarity:.4f}")
    print(f"AI-generated code similarity: {ai_similarity:.4f}")
    print(f"Difference: {similarity_diff:.4f}")

    # Interpret results
    if similarity_diff <= 0.04:
        result = "VERY LIKELY AI-GENERATED (similarity patterns almost identical)"
    elif similarity_diff <= 0.06:
        result = "LIKELY AI-GENERATED (similarity patterns very close)"
    elif similarity_diff <= 0.1:
        result = "POSSIBLY AI-GENERATED (similarity patterns somewhat close)"
    else:
        result = "LIKELY HUMAN-WRITTEN (similarity patterns differ significantly)"

    print(f"\nVERDICT: {result}")

    return {
        "original_similarity": original_similarity,
        "ai_similarity": ai_similarity,
        "difference": similarity_diff,
        "result": result,
    }


# Example usage
if __name__ == "__main__":
    # Test code
    code_to_test = """
#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

class File {
public:
    std::string name;
    size_t size;

    File(const std::string& name, size_t size) : name(name), size(size) {}

    std::string getName() const {
        return name;
    }

    size_t getSize() const {
        return size;
    }
};

class FileAVL {
private:
    struct Node {
        File* file;
        Node* left;
        Node* right;
        int height;

        Node(File* file) : file(file), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int height(Node* node) {
        return node ? node->height : 0;
    }

    int balanceFactor(Node* node) {
        return height(node->left) - height(node->right);
    }

    void updateHeight(Node* node) {
        node->height = std::max(height(node->left), height(node->right)) + 1;
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }

    Node* balance(Node* node) {
        updateHeight(node);
        if (balanceFactor(node) > 1) {
            if (balanceFactor(node->left) < 0)
                node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balanceFactor(node) < -1) {
            if (balanceFactor(node->right) > 0)
                node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }

    Node* insert(Node* node, File* file) {
        if (!node) return new Node(file);

        if (file->getSize() < node->file->getSize()) {
            node->left = insert(node->left, file);
        } else {
            node->right = insert(node->right, file);
        }

        return balance(node);
    }

    void queryInRange(Node* node, size_t min, size_t max, std::vector<File*>& result) {
        if (!node) return;

        if (node->file->getSize() >= min && node->file->getSize() <= max) {
            result.push_back(node->file);
        }

        if (node->file->getSize() > min) {
            queryInRange(node->left, min, max, result);
        }

        if (node->file->getSize() < max) {
            queryInRange(node->right, min, max, result);
        }
    }

public:
    FileAVL() : root(nullptr) {}

    void addFile(File* file) {
        root = insert(root, file);
    }

    std::vector<File*> query(size_t min, size_t max) {
        if (min > max) std::swap(min, max);

        std::vector<File*> result;
        queryInRange(root, min, max, result);
        return result;
    }
};

class FileTrie {
private:
    struct TrieNode {
        std::unordered_set<File*> files;
        std::unordered_map<char, TrieNode*> children;
    };

    TrieNode* root;

    void toLowerCase(std::string& str) const {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    }

public:
    FileTrie() : root(new TrieNode()) {}

    void addFile(File* file) {
        TrieNode* node = root;
        std::string name = file->getName();
        toLowerCase(name);

        for (char c : name) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }

        node->files.insert(file);
    }

    std::unordered_set<File*> getFilesWithPrefix(const std::string& prefix) const {
        TrieNode* node = root;
        std::string lowerPrefix = prefix;
        toLowerCase(lowerPrefix);

        for (char c : lowerPrefix) {
            if (node->children.find(c) == node->children.end()) {
                return {};
            }
            node = node->children[c];
        }

        return node->files;
    }
};

int main() {
    // Testing the implementation
    File f1("fileA.txt", 100);
    File f2("fileB.txt", 200);
    File f3("fileC.txt", 150);

    // Testing FileAVL
    FileAVL fileAVL;
    fileAVL.addFile(&f1);
    fileAVL.addFile(&f2);
    fileAVL.addFile(&f3);

    auto files = fileAVL.query(100, 200);
    for (auto file : files) {
        std::cout << "File: " << file->getName() << ", Size: " << file->getSize() << "\n";
    }

    // Testing FileTrie
    FileTrie fileTrie;
    fileTrie.addFile(&f1);
    fileTrie.addFile(&f2);
    fileTrie.addFile(&f3);

    auto filesWithPrefix = fileTrie.getFilesWithPrefix("file");
    for (auto file : filesWithPrefix) {
        std::cout << "File: " << file->getName() << "\n";
    }

    return 0;
}

    """

    # Run enhanced detection
    detect_ai_generated_enhanced(code_to_test)
