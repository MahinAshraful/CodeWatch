import torch
import numpy as np
from pathlib import Path
from model_singleton import model_service
from transformers import RobertaTokenizer, RobertaModel

def get_code_embedding(code: str) ->  np.ndarray:
    """
    Takes in a code snippet and returns its vector embedding.

    Args: 
        code (str): The code snippet to be embedded.

    Returns:
        np.ndarray: A (1, D) array representing the [CLS] embedding vector. 
                    [CLS] is the special token that's treated as a representative summary
                    of the code snippet.
    """
    
    # Using CodeT5
    # return model_service.get_code_embedding(code)

    # --- OR ---

    # Using fine-tuned model (Comment the above line)
    try:
        # Getting the absolute path of the fine-tuned model
        model_path = Path(__file__).resolve().parent.parent.parent / "training-model" / "graphcodebert-cpp-simcse"
        
        # Convert to string and make sure it exists
        model_path_str = str(model_path)
        print(f"Loading model from: {model_path_str}")
        
        if not Path(model_path_str).exists():
            print(f"Model path does not exist: {model_path_str}")
            return model_service.get_code_embedding(code)  # Fallback to model_service

        # Initializing the tokenizer and model - specify local_files_only=True to ensure local loading
        tokenizer = RobertaTokenizer.from_pretrained(
            model_path_str, 
            local_files_only=True
        )
        
        model = RobertaModel.from_pretrained(
            model_path_str,
            local_files_only=True
        )

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
        print("Falling back to model_service...")
        # Fallback to model_service if custom model fails
        return model_service.get_code_embedding(code)

def reshape_embedding(emb: np.ndarray) -> np.ndarray:
    """
    Reshapes a 1D embedding vector into a 2D row vector of shape (1, D).

    Crucial for compatibility with functions like cosine similarity,
    which expect inputs with shape (N, D). If the input is already 2D, 
    it is returned unchanged.

    Args:
        emb (np.ndarray): A 1D or 2D NumPy array representing an embedding.

    Returns:
        np.ndarray: A 2D NumPy array with shape (1, D).
    """

    if isinstance(emb, np.ndarray) and emb.ndim == 1:   # Reshape if not 2 dimension
        return emb.reshape(1, -1)
    
    return emb                                          # Else already (1, D)