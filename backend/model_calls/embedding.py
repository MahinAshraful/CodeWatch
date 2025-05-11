import torch
import numpy as np
from pathlib import Path
from transformers import RobertaTokenizer, RobertaModel

def get_code_embedding(code: str) ->  np.ndarray:
    """Takes in a code snippet and returns its vector embedding

    Args: 
        code (str): The code snippet to be embedded

    Returns:
        np.ndarray: A (1, D) array representing the [CLS] embedding vector. 
                    [CLS] is the special token that's treated as a representative summary
                    of the code snippet
    """

    try:
        # Getting the absolute path of the fine-tuned model
        model_path = Path(__file__).resolve().parent.parent.parent / "training-model" / "graphcodebert-cpp-simcse"

        # Initializing the tokenizer and model
        tokenizer = RobertaTokenizer.from_pretrained(model_path)
        model = RobertaModel.from_pretrained(model_path)

        # Using CUDA if exist for faster inferencing
        device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        model.to(device)

        # Tokenizing the code snippet and transferring them to CPU/GPU
        inputs = tokenizer(code, return_tensors="pt", truncation=True, max_length=512)
        inputs = {k: v.to(device) for k, v in inputs.items()}

        # Getting the cls embedding
        with torch.no_grad():
            outputs = model(**inputs)
        cls_embedding = outputs.last_hidden_state[:, 0, :]

        return cls_embedding.cpu().numpy()
    
    except Exception as e:
        print(f"Error getting the embedding: {e}")
        return None

def reshape_embedding(emb):
    """Ensure embedding is shape (1, D) for cosine similarity."""
    if isinstance(emb, np.ndarray) and emb.ndim == 1:
        return emb.reshape(1, -1)
    return emb  # assume already (1, D)

def main():
    print(get_code_embedding("Hello, World!"))

    pass

if __name__ == "__main__":
    main()