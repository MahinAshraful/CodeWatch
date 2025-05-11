import openai
import os
import asyncio
import time
import numpy as np
from pathlib import Path
from sklearn.metrics.pairwise import cosine_similarity

from dotenv import load_dotenv
from typing import Any
import warnings

from .embedding import get_code_embedding

warnings.filterwarnings("ignore")
load_dotenv()

# --- Import OpenAI key and setup client ---
client = openai.OpenAI(api_key=os.getenv("OPENAI_API_KEY"))

def load_prompt(template_path: str, code: str) -> str:
    """
    Load a template prompt and insert a code snippet into the {code} placeholder.
    
    Args:
        template_path (str): The file path of the at which the prompt is located.
        code (str): The code snippet to be inserted in the template.

    Returns:
        str: the formatted prompt ready to be sent to LLM services.
    """

    template = Path(template_path).read_text()

    return template.format(filler=code)
    
# --- Rewriting function and its Synchronous Wrapper ---
async def rewrite_code_async(code: str, index: int = 0, retry_attempts: int = 1, retry_delay: int = 30):
    """This function takes in a code snippnet"""

    # Load prompt template and inject the problem statement inside
    PROMPT_PATH = Path(__file__).resolve().parent / "prompts/rewrite_code.txt"
    prompt = load_prompt(PROMPT_PATH, code)

    return prompt

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
def rewrite_code(code, retry_attempts=1, retry_delay=30):
    """Synchronous wrapper for rewrite_code_async"""
    return asyncio.run(rewrite_code_async(code, 0, retry_attempts, retry_delay))
# --- End: Rewriting function and its Synchronous Wrapper ---

# --- DONE ---
def extract_problem_statement(code: str, retry_attempts: int = 1, retry_delay: int = 30) -> str:
    """
    Extract the problem statement/task that the code is solving using GPT.
    
    Args:
        code (str): A code snippet to have its problem statement/task extracted.
        retry_attempts (int): Nmber of retries on rate limit
        retry_delay (int): Delay in seconds between retries. Prevent spamming
    
    Returns:
        str: The extracted problem statement, or an error if fails
    
    """

    # Load prompt template and inject the code inside
    PROMPT_PATH = Path(__file__).resolve().parent / "prompts/extract_problem_statement.txt"
    prompt = load_prompt(PROMPT_PATH, code)

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

# --- DONE ---
def generate_code_from_problem(problem_statement, retry_attempts=1, retry_delay=30):
    """Generate code from the extracted problem statement using GPT"""

    # Load prompt template and inject the problem statement inside
    PROMPT_PATH = Path(__file__).resolve().parent / "prompts/generate_code_from_problem.txt"
    prompt = load_prompt(PROMPT_PATH, problem_statement)

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


def reshape_embedding(emb):
    """Ensure embedding is shape (1, D) for cosine similarity."""
    if isinstance(emb, np.ndarray) and emb.ndim == 1:
        return emb.reshape(1, -1)
    return emb  # assume already (1, D)


async def detect_ai_generated_async(code, num_rewrites=1, min_rewrites=1):
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

    original_embedding = reshape_embedding(original_embedding)

    similarities = []
    for i, rewrite in enumerate(rewrites):
        emb = get_code_embedding(rewrite)
        if emb is not None:
            emb = reshape_embedding(emb)
            similarity = cosine_similarity(original_embedding, emb)[0][0]
            similarities.append(similarity)
            print(f"Similarity for rewrite {i+1}: {similarity:.4f}")
        else:
            print(f"Failed to get embedding for rewrite {i+1}")

    if not similarities:
        print("No similarity scores could be calculated.")
        return None

    avg_similarity = sum(similarities) / len(similarities)
    print(
        f"Average similarity score (from {len(similarities)} rewrites): {avg_similarity:.4f}"
    )
    return avg_similarity

# --- Detection and its synchronous wrapper ---
async def detect_ai_generated_enhanced_async(code: str, num_rewrites=1, min_rewrites=1):
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
    elif similarity_diff <= 0.15:
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

def detect_ai_generated_enhanced(code: str, num_rewrites: int = 1, min_rewrites: int = 1) -> dict[str: Any]:
    """Synchronous wrapper for detect_ai_generated_enhanced_async"""

    return asyncio.run(
        detect_ai_generated_enhanced_async(code, num_rewrites, min_rewrites)
    )
# --- End: Detection and its synchronous wrapper ---

# def detect_ai_generated(code, num_rewrites=1, min_rewrites=1):
#     """Synchronous wrapper for detect_ai_generated_async"""
#     return asyncio.run(detect_ai_generated_async(code, num_rewrites, min_rewrites))

if __name__ == "__main__":
    # # Test code
    code_to_test = """
    """

    detect_ai_generated_enhanced(code_to_test)

    # print(extract_problem_statement("Hello Word"))                  # Works
    # print(generate_code_from_problem("Hello World"))                # Works
    # print(rewrite_code("Hello"))                                    # Works  

