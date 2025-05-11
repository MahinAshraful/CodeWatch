import torch
from transformers import AutoModel, AutoTokenizer
import os


class ModelSingleton:
    _instance = None
    _initialized = False

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(ModelSingleton, cls).__new__(cls)
        return cls._instance

    def __init__(self):
        if not self._initialized:
            print("Initializing CodeT5+ model (this should only happen once)...")
            # Choose device for computation
            self.device = "cuda" if torch.cuda.is_available() else "cpu"
            print(f"Using device: {self.device}")

            # Load tokenizer and model once
            checkpoint = "Salesforce/codet5p-110m-embedding"
            self.tokenizer = AutoTokenizer.from_pretrained(
                checkpoint, trust_remote_code=True
            )
            self.model = AutoModel.from_pretrained(
                checkpoint, trust_remote_code=True
            ).to(self.device)

            ModelSingleton._initialized = True
            print("Model initialization complete")

    def get_code_embedding(self, code):
        try:
            inputs = self.tokenizer.encode(code, return_tensors="pt").to(self.device)

            # Handle potential input length issues
            if inputs.shape[1] > 512:
                inputs = inputs[:, :512]

            with torch.no_grad():
                embedding = self.model(inputs)[0]

            return embedding.cpu().numpy()
        except Exception as e:
            print(f"Error getting embedding: {e}")
            return None


# Create a global instance to be imported by other modules
model_service = ModelSingleton()
