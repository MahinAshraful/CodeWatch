import React, { useState, useEffect, useRef } from 'react';

const HowItWorksPage: React.FC = () => {
  const [activeSection, setActiveSection] = useState<string>('intuition');
  const [isVisible, setIsVisible] = useState<boolean>(false);
  const sectionsRef = useRef<{[key: string]: HTMLElement | null}>({});

  // Animation on load
  useEffect(() => {
    setIsVisible(true);
    
    // Set up intersection observer for sections
    const observer = new IntersectionObserver((entries) => {
      entries.forEach(entry => {
        if (entry.isIntersecting) {
          const id = entry.target.id;
          setActiveSection(id);
        }
      });
    }, { threshold: 0.5 });
    
    // Observe each section
    Object.values(sectionsRef.current).forEach(section => {
      if (section) observer.observe(section);
    });
    
    return () => observer.disconnect();
  }, []);

  const scrollToSection = (sectionId: string) => {
    const section = document.getElementById(sectionId);
    if (section) {
      section.scrollIntoView({ behavior: 'smooth' });
    }
  };

  return (
    <div className={`max-w-6xl mx-auto py-12 px-6 transition-all duration-700 ${isVisible ? 'opacity-100' : 'opacity-0 translate-y-8'}`}>
      {/* Floating navigation */}
      <div className="fixed right-8 top-1/2 -translate-y-1/2 z-10 hidden xl:block">
        <div className="bg-slate-800/80 backdrop-blur-sm rounded-xl border border-slate-700/50 shadow-lg p-3">
          <nav>
            <ul className="space-y-3">
              <li>
                <button 
                  onClick={() => scrollToSection('intuition')}
                  className={`w-10 h-10 flex items-center justify-center rounded-lg transition-all ${
                    activeSection === 'intuition' 
                      ? 'bg-blue-600 text-white shadow-md' 
                      : 'bg-slate-700/50 text-slate-400 hover:bg-slate-700'
                  }`}
                  title="Key Intuition"
                >
                  <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                    <path strokeLinecap="round" strokeLinejoin="round" d="M9.663 17h4.673M12 3v1m6.364 1.636l-.707.707M21 12h-1M4 12H3m3.343-5.657l-.707-.707m2.828 9.9a5 5 0 117.072 0l-.548.547A3.374 3.374 0 0014 18.469V19a2 2 0 11-4 0v-.531c0-.895-.356-1.754-.988-2.386l-.548-.547z" />
                  </svg>
                </button>
              </li>
              <li>
                <button 
                  onClick={() => scrollToSection('detection')}
                  className={`w-10 h-10 flex items-center justify-center rounded-lg transition-all ${
                    activeSection === 'detection' 
                      ? 'bg-blue-600 text-white shadow-md' 
                      : 'bg-slate-700/50 text-slate-400 hover:bg-slate-700'
                  }`}
                  title="How Detection Works"
                >
                  <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                    <path strokeLinecap="round" strokeLinejoin="round" d="M9 5H7a2 2 0 00-2 2v12a2 2 0 002 2h10a2 2 0 002-2V7a2 2 0 00-2-2h-2M9 5a2 2 0 002 2h2a2 2 0 002-2M9 5a2 2 0 012-2h2a2 2 0 012 2m-3 7h3m-3 4h3m-6-4h.01M9 16h.01" />
                  </svg>
                </button>
              </li>
              <li>
                <button 
                  onClick={() => scrollToSection('technical')}
                  className={`w-10 h-10 flex items-center justify-center rounded-lg transition-all ${
                    activeSection === 'technical' 
                      ? 'bg-blue-600 text-white shadow-md' 
                      : 'bg-slate-700/50 text-slate-400 hover:bg-slate-700'
                  }`}
                  title="Technical Details"
                >
                  <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                    <path strokeLinecap="round" strokeLinejoin="round" d="M10 20l4-16m4 4l4 4-4 4M6 16l-4-4 4-4" />
                  </svg>
                </button>
              </li>
              <li>
                <button 
                  onClick={() => scrollToSection('research')}
                  className={`w-10 h-10 flex items-center justify-center rounded-lg transition-all ${
                    activeSection === 'research' 
                      ? 'bg-blue-600 text-white shadow-md' 
                      : 'bg-slate-700/50 text-slate-400 hover:bg-slate-700'
                  }`}
                  title="Research Paper"
                >
                  <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                    <path strokeLinecap="round" strokeLinejoin="round" d="M9 12h6m-6 4h6m2 5H7a2 2 0 01-2-2V5a2 2 0 012-2h5.586a1 1 0 01.707.293l5.414 5.414a1 1 0 01.293.707V19a2 2 0 01-2 2z" />
                  </svg>
                </button>
              </li>
            </ul>
          </nav>
        </div>
      </div>

      {/* Header */}
      <div className="relative mb-20">
        {/* Background elements */}
        <div className="absolute -top-10 -left-10 w-40 h-40 bg-blue-600/10 rounded-full blur-3xl pointer-events-none"></div>
        <div className="absolute -bottom-10 -right-10 w-40 h-40 bg-indigo-600/10 rounded-full blur-3xl pointer-events-none"></div>
        
<div className="text-center my-16">
  <h1 
    className="text-5xl md:text-6xl lg:text-7xl font-bold text-transparent bg-clip-text bg-gradient-to-r from-blue-400 to-indigo-500 inline-block transition-transform duration-300 ease-in-out transform hover:scale-105"
  >
    How It Works
  </h1>
  
  <p className="text-lg md:text-xl text-gray-300 max-w-4xl mx-auto mt-8">
    CodeWatch leverages the unique characteristics of Large Language Models to detect AI-generated
    code. Our approach is based on the observation that AI models generate code by predicting the most
    likely next token, while humans write code with more distinctive personal styles and patterns.
  </p>
</div>
        
        {/* Navigation Pills */}
        <div className="flex flex-wrap justify-center gap-3 mt-10">
          <button 
            onClick={() => scrollToSection('intuition')}
            className={`px-4 py-2 rounded-full transition-all font-medium ${
              activeSection === 'intuition' 
                ? 'bg-blue-600 text-white shadow-lg' 
                : 'bg-slate-800 text-slate-300 hover:bg-slate-700'
            }`}
          >
            Key Intuition
          </button>
          <button 
            onClick={() => scrollToSection('detection')}
            className={`px-4 py-2 rounded-full transition-all font-medium ${
              activeSection === 'detection' 
                ? 'bg-blue-600 text-white shadow-lg' 
                : 'bg-slate-800 text-slate-300 hover:bg-slate-700'
            }`}
          >
            Detection Process
          </button>
          <button 
            onClick={() => scrollToSection('technical')}
            className={`px-4 py-2 rounded-full transition-all font-medium ${
              activeSection === 'technical' 
                ? 'bg-blue-600 text-white shadow-lg' 
                : 'bg-slate-800 text-slate-300 hover:bg-slate-700'
            }`}
          >
            Technical Details
          </button>
          <button 
            onClick={() => scrollToSection('research')}
            className={`px-4 py-2 rounded-full transition-all font-medium ${
              activeSection === 'research' 
                ? 'bg-blue-600 text-white shadow-lg' 
                : 'bg-slate-800 text-slate-300 hover:bg-slate-700'
            }`}
          >
            Research Paper
          </button>
        </div>
      </div>
      
      <div className="space-y-24">
        {/* Main content section */}
        <div className="prose prose-invert prose-lg max-w-none">
          {/* Intuition Section */}
          <section 
            id="intuition" 
            ref={el => sectionsRef.current['intuition'] = el}
            className="relative"
          >
            <div className="absolute -left-16 top-6 hidden lg:block">
              <div className={`h-12 w-1 bg-blue-500/50 rounded transition-all ${activeSection === 'intuition' ? 'opacity-100' : 'opacity-0'}`}></div>
            </div>
            
            <div className="bg-slate-800/30 rounded-2xl p-8 border border-slate-700/50 shadow-lg backdrop-blur-sm transition-all hover:shadow-blue-900/5">
              <h2 className="text-3xl font-bold text-gray-100 mb-6 flex items-center">
                <div className="bg-blue-600/20 p-2 rounded-lg mr-3">
                  <svg xmlns="http://www.w3.org/2000/svg" className="h-6 w-6 text-blue-400" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                    <path strokeLinecap="round" strokeLinejoin="round" d="M9.663 17h4.673M12 3v1m6.364 1.636l-.707.707M21 12h-1M4 12H3m3.343-5.657l-.707-.707m2.828 9.9a5 5 0 117.072 0l-.548.547A3.374 3.374 0 0014 18.469V19a2 2 0 11-4 0v-.531c0-.895-.356-1.754-.988-2.386l-.548-.547z" />
                  </svg>
                </div>
                Key Intuition
              </h2>
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

              {/* Visual representation */}
              <div className="mt-8 bg-slate-900/60 rounded-xl p-6 border border-slate-800">
                <div className="flex flex-col lg:flex-row gap-6">
                  <div className="flex-1 bg-slate-800/50 rounded-lg p-4 border border-slate-700/50">
                    <h3 className="text-blue-400 font-medium mb-3 text-center">AI Code Generation</h3>
                    <div className="relative h-40">
                      {/* Token prediction visualization */}
                      <div className="absolute inset-0 flex items-center justify-center">
                        <svg width="200" height="120" viewBox="0 0 200 120" className="mx-auto">
                          <path 
                            d="M20,60 C50,30 150,30 180,60" 
                            stroke="#3b82f6" 
                            strokeWidth="2" 
                            fill="none" 
                            strokeDasharray="5,5"
                          />
                          <circle cx="20" cy="60" r="5" fill="#3b82f6" />
                          <circle cx="60" cy="40" r="5" fill="#3b82f6" />
                          <circle cx="100" cy="35" r="5" fill="#3b82f6" />
                          <circle cx="140" cy="40" r="5" fill="#3b82f6" />
                          <circle cx="180" cy="60" r="5" fill="#3b82f6" />
                          
                          <text x="20" y="75" fill="#94a3b8" fontSize="10" textAnchor="middle">t1</text>
                          <text x="60" y="55" fill="#94a3b8" fontSize="10" textAnchor="middle">t2</text>
                          <text x="100" y="50" fill="#94a3b8" fontSize="10" textAnchor="middle">t3</text>
                          <text x="140" y="55" fill="#94a3b8" fontSize="10" textAnchor="middle">t4</text>
                          <text x="180" y="75" fill="#94a3b8" fontSize="10" textAnchor="middle">t5</text>
                        </svg>
                      </div>
                      <div className="absolute bottom-0 inset-x-0 text-center text-sm text-slate-400">
                        Consistent token prediction pattern
                      </div>
                    </div>
                  </div>
                  
                  <div className="flex-1 bg-slate-800/50 rounded-lg p-4 border border-slate-700/50">
                    <h3 className="text-green-400 font-medium mb-3 text-center">Human Code Generation</h3>
                    <div className="relative h-40">
                      {/* Human variation visualization */}
                      <div className="absolute inset-0 flex items-center justify-center">
                        <svg width="200" height="120" viewBox="0 0 200 120" className="mx-auto">
                          <path 
                            d="M20,60 C40,80 70,20 100,60 C130,90 150,30 180,60" 
                            stroke="#22c55e" 
                            strokeWidth="2" 
                            fill="none"
                          />
                          <circle cx="20" cy="60" r="5" fill="#22c55e" />
                          <circle cx="60" cy="30" r="5" fill="#22c55e" />
                          <circle cx="100" cy="60" r="5" fill="#22c55e" />
                          <circle cx="140" cy="80" r="5" fill="#22c55e" />
                          <circle cx="180" cy="60" r="5" fill="#22c55e" />
                          
                          <text x="20" y="75" fill="#94a3b8" fontSize="10" textAnchor="middle">t1</text>
                          <text x="60" y="45" fill="#94a3b8" fontSize="10" textAnchor="middle">t2</text>
                          <text x="100" y="75" fill="#94a3b8" fontSize="10" textAnchor="middle">t3</text>
                          <text x="140" y="95" fill="#94a3b8" fontSize="10" textAnchor="middle">t4</text>
                          <text x="180" y="75" fill="#94a3b8" fontSize="10" textAnchor="middle">t5</text>
                        </svg>
                      </div>
                      <div className="absolute bottom-0 inset-x-0 text-center text-sm text-slate-400">
                        Variable, unique coding patterns
                      </div>
                    </div>
                  </div>
                </div>
              </div>
            </div>
          </section>

          {/* Detection Process Section */}
          <section 
            id="detection" 
            ref={el => sectionsRef.current['detection'] = el}
            className="relative mt-24"
          >
            <div className="absolute -left-16 top-6 hidden lg:block">
              <div className={`h-12 w-1 bg-blue-500/50 rounded transition-all ${activeSection === 'detection' ? 'opacity-100' : 'opacity-0'}`}></div>
            </div>
            
            <div className="bg-slate-800/30 rounded-2xl p-8 border border-slate-700/50 shadow-lg backdrop-blur-sm">
              <h2 className="text-3xl font-bold text-gray-100 mb-6 flex items-center">
                <div className="bg-blue-600/20 p-2 rounded-lg mr-3">
                  <svg xmlns="http://www.w3.org/2000/svg" className="h-6 w-6 text-blue-400" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                    <path strokeLinecap="round" strokeLinejoin="round" d="M9 5H7a2 2 0 00-2 2v12a2 2 0 002 2h10a2 2 0 002-2V7a2 2 0 00-2-2h-2M9 5a2 2 0 002 2h2a2 2 0 002-2M9 5a2 2 0 012-2h2a2 2 0 012 2m-3 7h3m-3 4h3m-6-4h.01M9 16h.01" />
                  </svg>
                </div>
                How Detection Works
              </h2>
              
              <div className="space-y-6">
                {/* Step 1 */}
                <div className="flex">
                  <div className="flex-shrink-0 flex items-start">
                    <div className="h-10 w-10 bg-blue-500/20 rounded-full flex items-center justify-center text-blue-400 font-bold border border-blue-500/30">
                      1
                    </div>
                    <div className="h-full w-0.5 bg-slate-700 mx-auto mt-2"></div>
                  </div>
                  <div className="ml-4 bg-slate-800/50 p-4 rounded-lg border border-slate-700/30 flex-1">
                    <h3 className="text-lg font-medium text-white">Submit your code for analysis</h3>
                    <p className="text-slate-400 mt-1">
                      Use our web interface to submit your code snippet in any supported programming language.
                    </p>
                  </div>
                </div>
                
                {/* Step 2 */}
                <div className="flex">
                  <div className="flex-shrink-0 flex items-start">
                    <div className="h-10 w-10 bg-blue-500/20 rounded-full flex items-center justify-center text-blue-400 font-bold border border-blue-500/30">
                      2
                    </div>
                    <div className="h-full w-0.5 bg-slate-700 mx-auto mt-2"></div>
                  </div>
                  <div className="ml-4 bg-slate-800/50 p-4 rounded-lg border border-slate-700/30 flex-1">
                    <h3 className="text-lg font-medium text-white">Our system uses an LLM to understand and rewrite the code</h3>
                    <p className="text-slate-400 mt-1">
                      Advanced language models interpret the code structure and functionality, then generate multiple rewrites.
                    </p>
                  </div>
                </div>
                
                {/* Step 3 */}
                <div className="flex">
                  <div className="flex-shrink-0 flex items-start">
                    <div className="h-10 w-10 bg-blue-500/20 rounded-full flex items-center justify-center text-blue-400 font-bold border border-blue-500/30">
                      3
                    </div>
                    <div className="h-full w-0.5 bg-slate-700 mx-auto mt-2"></div>
                  </div>
                  <div className="ml-4 bg-slate-800/50 p-4 rounded-lg border border-slate-700/30 flex-1">
                    <h3 className="text-lg font-medium text-white">We compare the original code with multiple AI rewrites</h3>
                    <p className="text-slate-400 mt-1">
                      Our algorithms analyze structural and semantic differences between the original and rewritten versions.
                    </p>
                  </div>
                </div>
                
                {/* Step 4 */}
                <div className="flex">
                  <div className="flex-shrink-0 flex items-start">
                    <div className="h-10 w-10 bg-blue-500/20 rounded-full flex items-center justify-center text-blue-400 font-bold border border-blue-500/30">
                      4
                    </div>
                    <div className="h-full w-0.5 bg-slate-700 mx-auto mt-2"></div>
                  </div>
                  <div className="ml-4 bg-slate-800/50 p-4 rounded-lg border border-slate-700/30 flex-1">
                    <h3 className="text-lg font-medium text-white">Code embeddings are generated using CodeT5+</h3>
                    <p className="text-slate-400 mt-1">
                      We convert code into vector representations that capture its structure and semantic characteristics.
                    </p>
                  </div>
                </div>
                
                {/* Step 5 */}
                <div className="flex">
                  <div className="flex-shrink-0">
                    <div className="h-10 w-10 bg-blue-500/20 rounded-full flex items-center justify-center text-blue-400 font-bold border border-blue-500/30">
                      5
                    </div>
                  </div>
                  <div className="ml-4 bg-slate-800/50 p-4 rounded-lg border border-slate-700/30 flex-1">
                    <h3 className="text-lg font-medium text-white">Cosine similarity analysis reveals whether the code was likely written by a human or AI</h3>
                    <p className="text-slate-400 mt-1">
                      The final verdict is determined by comparing similarity patterns between original and rewritten code versions.
                    </p>
                  </div>
                </div>
              </div>
            </div>
          </section>

          {/* Technical Details Section */}
<section 
  id="technical" 
  ref={el => sectionsRef.current['technical'] = el} 
  className="relative mt-24"
>
  <div className="absolute -left-16 top-6 hidden lg:block">
    <div className={`h-12 w-1 bg-blue-500/50 rounded transition-all ${activeSection === 'technical' ? 'opacity-100' : 'opacity-0'}`}></div>
  </div>
  
  <div className="bg-slate-800/30 rounded-2xl p-8 border border-slate-700/50 shadow-lg backdrop-blur-sm">
    <h2 className="text-3xl font-bold text-gray-100 mb-6 flex items-center">
      <div className="bg-blue-600/20 p-2 rounded-lg mr-3">
        <svg xmlns="http://www.w3.org/2000/svg" className="h-6 w-6 text-blue-400" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
          <path strokeLinecap="round" strokeLinejoin="round" d="M10 20l4-16m4 4l4 4-4 4M6 16l-4-4 4-4" />
        </svg>
      </div>
      Technical Details
    </h2>
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
    
    {/* Technical representation */}
    <div className="mt-8 grid grid-cols-1 md:grid-cols-2 gap-6">
      <div className="bg-slate-900/60 rounded-lg p-5 border border-slate-700/50">
        <h3 className="text-blue-400 font-medium mb-3">Embedding Generation Process</h3>
        <pre className="text-sm bg-slate-950 p-4 rounded-lg overflow-x-auto text-slate-300">
          <code>
{`# Generate code embeddings using CodeT5+
def get_code_embedding(code):
    inputs = tokenizer.encode(code)
    with torch.no_grad():
        embedding = model(inputs)[0]
    return embedding.cpu().numpy()`}
          </code>
        </pre>
      </div>
      
      <div className="bg-slate-900/60 rounded-lg p-5 border border-slate-700/50">
        <h3 className="text-blue-400 font-medium mb-3">Similarity Analysis</h3>
        <pre className="text-sm bg-slate-950 p-4 rounded-lg overflow-x-auto text-slate-300">
          <code>
{`# Compare embeddings using cosine similarity
def compare_embeddings(original, rewrite):
    emb_original = get_code_embedding(original)
    emb_rewrite = get_code_embedding(rewrite)
    
    similarity = cosine_similarity(
        [emb_original], [emb_rewrite]
    )[0][0]
    
    return similarity`}
          </code>
        </pre>
      </div>
    </div>
  </div>
</section>
          {/* Research Paper Section */}
          <section 
            id="research" 
            ref={el => sectionsRef.current['research'] = el}
            className="relative mt-24"
          >
            <div className="absolute -left-16 top-6 hidden lg:block">
              <div className={`h-12 w-1 bg-blue-500/50 rounded transition-all ${activeSection === 'research' ? 'opacity-100' : 'opacity-0'}`}></div>
            </div>
            
            <div className="bg-slate-800/30 rounded-2xl p-8 border border-slate-700/50 shadow-lg backdrop-blur-sm">
              <h2 className="text-3xl font-bold text-gray-100 mb-6 flex items-center">
                <div className="bg-blue-600/20 p-2 rounded-lg mr-3">
                  <svg xmlns="http://www.w3.org/2000/svg" className="h-6 w-6 text-blue-400" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                    <path strokeLinecap="round" strokeLinejoin="round" d="M9 12h6m-6 4h6m2 5H7a2 2 0 01-2-2V5a2 2 0 012-2h5.586a1 1 0 01.707.293l5.414 5.414a1 1 0 01.293.707V19a2 2 0 01-2 2z" />
                  </svg>
                </div>
                Research Paper
              </h2>
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
              
              <div className="mt-8 flex items-center gap-4">
                <a 
                  href="/static/pdfs/research-paper.pdf" 
                  className="px-5 py-3 bg-blue-600 hover:bg-blue-700 text-white font-medium rounded-lg transition-all duration-300 flex items-center shadow-lg hover:shadow-blue-900/20"
                  target="_blank"
                  rel="noopener noreferrer"
                >
                  <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5 mr-2" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                    <path strokeLinecap="round" strokeLinejoin="round" d="M4 16v1a3 3 0 003 3h10a3 3 0 003-3v-1m-4-4l-4 4m0 0l-4-4m4 4V4" />
                  </svg>
                  Download Paper
                </a>
                
                <a 
                  href="#viewPaper" 
                  className="px-5 py-3 bg-slate-700 hover:bg-slate-600 text-white font-medium rounded-lg transition-all duration-300 flex items-center"
                >
                  <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5 mr-2" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                    <path strokeLinecap="round" strokeLinejoin="round" d="M15 12a3 3 0 11-6 0 3 3 0 016 0z" />
                    <path strokeLinecap="round" strokeLinejoin="round" d="M2.458 12C3.732 7.943 7.523 5 12 5c4.478 0 8.268 2.943 9.542 7-1.274 4.057-5.064 7-9.542 7-4.477 0-8.268-2.943-9.542-7z" />
                  </svg>
                  View Preview
                </a>
              </div>
              
< div className="mt-6">
                <embed 
                  src="/static/pdfs/research-paper.pdf"
                  type="application/pdf"
                  className="w-full h-[600px] rounded-lg border border-slate-700"
                />
              
      </div>
            </div>
          </section>
        </div>
      </div>
    </div>
  );
};

export default HowItWorksPage;

