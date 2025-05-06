import torch
import numpy as np
from transformers import RobertaTokenizer, RobertaModel

def get_code_embedding(code: str) ->  np.ndarray:
    """Takes in a code snippet and returns its vector embedding

    Args: 
        code (str): The code snippet to be embedded

    Returns:
        np.ndarray: A (1, D) array
    """

    try:

        # Loading model and setting up
        model_path = "CodeWatch/training-model/graphcodebert-cpp-simcse"
        tokenizer = RobertaTokenizer.from_pretrained(model_path)
        model = RobertaModel.from_pretrained(model_path)
        device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
        model.to(device)

        # Tokenize move to device of choice
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
