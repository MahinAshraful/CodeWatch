import os
import numpy as np
from sklearn.metrics.pairwise import cosine_similarity
from dotenv import load_dotenv
from transformers import AutoModel, AutoTokenizer
import torch
import openai
import time

# Load environment variables
load_dotenv()

# Set up OpenAI API for rewriting code
openai.api_key = os.getenv("OPENAI_API_KEY")
client = openai.OpenAI(api_key=os.getenv("OPENAI_API_KEY"))

# Set up CodeT5+ for code embeddings
device = "cuda" if torch.cuda.is_available() else "cpu"
checkpoint = "Salesforce/codet5p-110m-embedding"
tokenizer = AutoTokenizer.from_pretrained(checkpoint, trust_remote_code=True)
model = AutoModel.from_pretrained(checkpoint, trust_remote_code=True).to(device)


def get_code_embedding(code):
    """Get code embeddings using CodeT5+."""
    try:
        inputs = tokenizer.encode(code, return_tensors="pt").to(device)
        # Handle potential input length issues
        if inputs.shape[1] > 512:
            inputs = inputs[:, :512]
        with torch.no_grad():
            embedding = model(inputs)[0]
        return embedding.cpu().numpy()
    except Exception as e:
        print(f"Error getting embedding: {e}")
        return None


def rewrite_code(code, retry_attempts=3, retry_delay=60):
    """Have GPT-3.5 Turbo rewrite the given code snippet with retry logic."""
    prompt = f"""
    ### Code:
    {code}
    ### Instruction:
    Please explain the functionality of the given code, then rewrite it in a single markdown code block. First find out what the code is doing and what is for, and then rewrite it from scratch. No additional clarifications.
    """

    for attempt in range(retry_attempts):
        try:
            response = client.chat.completions.create(
                model="gpt-3.5-turbo",
                messages=[
                    {
                        "role": "system",
                        "content": "You are a helpful assistant that rewrites code.",
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
                    if rewritten_code.startswith("python") or rewritten_code.startswith(
                        "java"
                    ):
                        rewritten_code = rewritten_code.split("\n", 1)[1]
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


def detect_ai_generated(code, num_rewrites=4, min_rewrites=1):
    """Detect if code is AI-generated, with tolerance for partial results."""
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


def compare_code_pair(code1, code2):
    """Compare similarity between two code snippets using CodeT5+."""
    print("Getting embeddings...")
    embedding1 = get_code_embedding(code1)
    embedding2 = get_code_embedding(code2)

    if embedding1 is None or embedding2 is None:
        print("Failed to get embeddings for one or both code snippets.")
        return None

    similarity = cosine_similarity([embedding1], [embedding2])[0][0]
    print(f"Similarity score: {similarity:.4f}")

    return similarity


# Example usage
if __name__ == "__main__":
    # For simple comparison between two code snippets
    code_1 = """
  def covered(room):
    grid = []
    for row in room:
        grid.append(list(row))
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j].isdigit():
                number = int(grid[i][j])
                for x in range(i-number, number + i+ 1):
                    for y in range(j-number, number + j +1 ):
                        if 0 <= x < rows and 0 <= y < cols:
                            if grid[x][y] == "#":
                                grid[x][y] = "C"

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == "#":
                return False

    return True
    """

    code_2 = """
    # Enter code 2 here
    """

    # Uncomment one of these:
    # similarity = compare_code_pair(code_1, code_2)
    similarity_score = detect_ai_generated(
        code_1, min_rewrites=1
    )  # Only need 1 rewrite minimum

    print("\nInterpretation based on the paper:")
    print("Higher similarity suggests AI-generated code")
    print("Lower similarity suggests human-written code")
