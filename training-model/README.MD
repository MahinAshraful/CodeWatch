# GraphCodeBERT-SimCSE for Synthetic Code Detection

This section provides our interpretation of the **code similarity model** training process described in the research paper:

> Ye, T., Du, Y., Ma, T., Wu, L., Zhang, X., Ji, S., & Wang, W. (2025).  
> *Uncovering LLM-Generated Code: A Zero-Shot Synthetic Code Detector via Code Rewriting.*  
> AAAI Conference on Artificial Intelligence. [[arXiv PDF]](https://doi.org/10.48550/arXiv.2405.16133)

---

## 📌 Overview
**Note:** This model was trained only on C++ data from CodeNet. For other languages, fine-tune separately.

Like the paper, we trained a GraphCodeBERT-based encoder using **SimCSE-style contrastive learning** to measure semantic similarity between code snippets. The key idea is to fine-tune it on unlabeled C++ code using unsupervised SimCSE so that the vector embedding of the code snippet can be more accurately represented

---

## 🧠 Core Concepts

- **SimCSE (Simple Contrastive Learning):** Contrastive learning using dropout as implicit data augmentation
- **GraphCodeBERT:** The base model for the training
- **Code Similarity Learning:** Train the model to produce similar embeddings for two augmented views of the same code snippet

---

## 🗂 Dataset

We use the [CodeNet](https://developer.ibm.com/data/project-codenet/) dataset — specifically the C++ subset. We provided some sample data in respective directory

---