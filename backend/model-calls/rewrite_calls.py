import openai
import os
from dotenv import load_dotenv
import warnings

warnings.filterwarnings("ignore")
load_dotenv()

# --- Import OpenAI key and setup client ---
client = openai.OpenAI(api_key=os.getenv("OPENAI_API_KEY"))

