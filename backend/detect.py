from model_singleton import model_service
from model_calls.rewrites import detect_ai_generated_enhanced
from model_calls.embedding import get_code_embedding

print("Warming up the model...")
dummy_code = "def hello(): print('Hello, world!')"
_ = model_service.get_code_embedding(dummy_code)
print("Model is ready to serve requests")

if __name__ == "__main__":
    # Test code
    code_to_test = """
    """

    # Run enhanced detection
    # detect_ai_generated_enhanced(code_to_test)
    get_code_embedding("Hello word")

    