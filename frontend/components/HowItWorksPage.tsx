import React from 'react';

const HowItWorksPage: React.FC = () => {
  return (
    <div className="max-w-6xl mx-auto py-12 px-6">
      <h1 className="text-5xl font-bold text-gray-100 mb-12">How It Works</h1>
      
      <div className="space-y-16">
        {/* Main content section */}
        <div className="prose prose-invert prose-lg max-w-none">
          <p className="text-xl text-gray-300 leading-relaxed mb-12">
            CodeWatch leverages the unique characteristics of Large Language Models to detect AI-generated code. 
            Our approach is based on the observation that AI models generate code by predicting the most likely 
            next token, while humans write code with more distinctive personal styles and patterns.
          </p>

          {/* Intuition Section */}
          <section className="mb-12">
            <h2 className="text-3xl font-bold text-gray-100 mb-6">Key Intuition</h2>
            <p className="text-lg text-gray-300">
              Generative LLMs "write" code by continuously predicting the next most likely token. When asked to write 
              code for a specific prompt, an LLM will likely produce similar answers because it consistently picks 
              from the most probable tokens.
            </p>
            <p className="text-lg text-gray-300 mt-4">
              Humans, however, code differently with unique styles. When we ask an LLM to rewrite human code, it typically 
              changes the structure significantly (using its token prediction method). But for AI-generated code, since it 
              was already created using token prediction, the changes are minimal.
            </p>
          </section>

          {/* Detection Process Section */}
          <section className="mb-12">
            <h2 className="text-3xl font-bold text-gray-100 mb-6">How Detection Works</h2>
            <p className="text-lg text-gray-300">
              1. Submit your code for analysis<br/>
              2. Our system uses an LLM to understand and rewrite the code<br/>
              3. We compare the original code with multiple AI rewrites<br/>
              4. Code embeddings are generated using CodeT5+<br/>
              5. Cosine similarity analysis reveals whether the code was likely written by a human or AI
            </p>
          </section>

          {/* Technical Details Section */}
          <section className="mb-16">
            <h2 className="text-3xl font-bold text-gray-100 mb-6">Technical Details</h2>
            <p className="text-lg text-gray-300">
              When analyzing AI-generated code, multiple rewrites show minimal structural changes 
              due to the consistent token prediction patterns. However, human-written code, when 
              rewritten by AI, shows significant structural variations. We measure these differences 
              using advanced embedding techniques and similarity comparisons.
            </p>
            <p className="text-lg text-gray-300 mt-4">
              Our system uses PyTorch and the CodeT5+ model for generating code embeddings, 
              combined with GPT-based rewrites for comprehensive pattern analysis. The similarity 
              scores provide confidence metrics to determine the likelihood of AI generation.
            </p>
          </section>

          {/* Research Paper Section */}
          <section className="mb-16">
            <h2 className="text-3xl font-bold text-gray-100 mb-6">Research Paper</h2>
            <p className="text-lg text-gray-300">
              Our research paper, "Detecting AI-Generated Code Using Token Prediction Patterns", explores the 
              fundamental differences between how humans and AI models approach code generation. The paper 
              presents a novel detection method based on code rewriting and embedding comparisons, achieving 
              over 90% accuracy in distinguishing between human-written and AI-generated code samples.
            </p>
            <p className="text-lg text-gray-300 mt-4">
              We demonstrate that while AI models maintain consistent patterns due to their token prediction 
              nature, human code exhibits greater structural diversity. This key insight forms the basis of 
              our detection methodology, which we validate across multiple programming languages and coding tasks.
            </p>
            <div className="mt-6">
              <embed 
                src="/static/pdfs/research-paper.pdf"
                type="application/pdf"
                className="w-full h-[600px] rounded-lg"
              />
            </div>
          </section>
        </div>
      </div>
    </div>
  );
};

export default HowItWorksPage;
