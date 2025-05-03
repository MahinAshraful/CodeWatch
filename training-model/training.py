import torch
import torch.nn.functional as F
import os

def load_cpp_snippets(root_dir, limit=None):
    snippets = []
    for root, _, files in os.walk(root_dir):
        for file in files:
            if file.endswith(".cpp"):
                path = os.path.join(root, file)
                try:
                    with open(path, "r", encoding="utf-8", errors="ignore") as f:
                        code = f.read().strip()
                        if code:
                            snippets.append(code)
                            if limit and len(snippets) >= limit:
                                return snippets
                except:
                    continue  # skip unreadable files
    return snippets

# Example usage
cpp_dir = "Project_CodeNet_C++1000"
code_snippets = load_cpp_snippets(cpp_dir, limit=1000)  # adjust limit as needed

from transformers import AutoTokenizer
from torch.utils.data import DataLoader

tokenizer = AutoTokenizer.from_pretrained("microsoft/graphcodebert-base")

def tokenize_batch(batch):
    return tokenizer(batch, return_tensors="pt", padding=True, truncation=True, max_length=256)

dataloader = DataLoader(code_snippets, batch_size=16, shuffle=True)


def simcse_unsup_loss(emb1, emb2, temperature=0.1):
    sim = F.cosine_similarity(emb1.unsqueeze(1), emb2.unsqueeze(0), dim=2)
    sim /= temperature
    labels = torch.arange(emb1.size(0)).to(emb1.device)
    return F.cross_entropy(sim, labels)

from transformers import AutoModel
from tqdm import tqdm

device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
model = AutoModel.from_pretrained("microsoft/graphcodebert-base").to(device)
optimizer = torch.optim.AdamW(model.parameters(), lr=2e-5)

model.train()

for epoch in range(3):
    total_loss = 0
    for batch in tqdm(dataloader):
        tokenized = tokenize_batch(batch)
        tokenized = {k: v.to(device) for k, v in tokenized.items()}

        outputs1 = model(**tokenized)
        outputs2 = model(**tokenized)

        out1 = outputs1.last_hidden_state[:, 0, :]  # [CLS]
        out2 = outputs2.last_hidden_state[:, 0, :]  # [CLS]


        loss = simcse_unsup_loss(out1, out2)
        loss.backward()
        optimizer.step()
        optimizer.zero_grad()

        total_loss += loss.item()
    
    print(f"Epoch {epoch + 1}: Loss = {total_loss:.4f}")

model.save_pretrained("graphcodebert-cpp-simcse")
tokenizer.save_pretrained("graphcodebert-cpp-simcse")
