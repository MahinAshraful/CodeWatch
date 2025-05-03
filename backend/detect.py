import os
import numpy as np
from sklearn.metrics.pairwise import cosine_similarity
from dotenv import load_dotenv
from transformers import AutoModel, AutoTokenizer
import torch
import openai
import time
import asyncio

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


async def rewrite_code_async(code, index=0, retry_attempts=3, retry_delay=60):
    """Async version of rewrite_code."""
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
                    print(f"Rewrite {index+1} complete")
                    return rewritten_code.strip()
            print(f"Rewrite {index+1} failed to parse markdown")
            return content

        except openai.RateLimitError as e:
            if attempt < retry_attempts - 1:
                print(
                    f"Rate limit hit for rewrite {index+1}, waiting {retry_delay} seconds before retry..."
                )
                await asyncio.sleep(retry_delay)  # use asyncio.sleep in async function
            else:
                print(f"All retry attempts failed for rewrite {index+1}: {e}")
                return code  # Return original code as fallback
        except Exception as e:
            print(f"Error during rewrite {index+1}: {e}")
            return code  # Return original code as fallback


def rewrite_code(code, retry_attempts=3, retry_delay=60):
    """Synchronous wrapper for rewrite_code_async"""
    return asyncio.run(rewrite_code_async(code, 0, retry_attempts, retry_delay))


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


async def detect_ai_generated_async(code, num_rewrites=3, min_rewrites=1):
    """Async version of detect_ai_generated"""
    print("Generating rewrites asynchronously...")

    # Create tasks for all rewrites to run concurrently
    rewrite_tasks = [rewrite_code_async(code, i) for i in range(num_rewrites)]

    # Wait for all rewrites to complete
    rewrite_results = await asyncio.gather(*rewrite_tasks)

    # Filter out unsuccessful rewrites
    rewrites = [rewrite for rewrite in rewrite_results if rewrite and rewrite != code]

    # Check if we have enough rewrites
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


def detect_ai_generated(code, num_rewrites=3, min_rewrites=1):
    """Synchronous wrapper for detect_ai_generated_async"""
    return asyncio.run(detect_ai_generated_async(code, num_rewrites, min_rewrites))


async def detect_ai_generated_enhanced_async(code, num_rewrites=3, min_rewrites=1):
    """Async enhanced detection comparing similarities between original code and AI-generated code."""
    print("====== STEP 1: Extracting Problem Statement ======")
    problem_statement = extract_problem_statement(code)

    print("\n====== STEP 2: Generating New Code from Problem Statement ======")
    ai_generated_code = generate_code_from_problem(problem_statement)
    print("\nAI-generated code from problem statement:")
    print("```")
    print(ai_generated_code)
    print("```")

    print("\n====== STEP 3 & 4: Testing Both Codes in Parallel ======")

    # Run both similarity tests concurrently
    original_task = detect_ai_generated_async(code, num_rewrites, min_rewrites)
    ai_task = detect_ai_generated_async(ai_generated_code, num_rewrites, min_rewrites)

    # Wait for both tasks to complete
    original_similarity, ai_similarity = await asyncio.gather(original_task, ai_task)

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


def detect_ai_generated_enhanced(code, num_rewrites=2, min_rewrites=1):
    """Synchronous wrapper for detect_ai_generated_enhanced_async"""
    return asyncio.run(
        detect_ai_generated_enhanced_async(code, num_rewrites, min_rewrites)
    )


# Example usage
if __name__ == "__main__":
    # Test code
    code_to_test = """


    """

    # Run enhanced detection
    detect_ai_generated_enhanced(code_to_test)
