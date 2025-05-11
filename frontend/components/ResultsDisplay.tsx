import React, { useEffect, useState } from 'react';
import ResultsVisualization from './ResultsVisualization';

interface ResultsDisplayProps {
  results: {
    original_similarity: number;
    ai_similarity: number;
    difference: number;
    result: string;
  };
}

const ResultsDisplay: React.FC<ResultsDisplayProps> = ({ results }) => {
  const [animate, setAnimate] = useState(false);
  
  useEffect(() => {
    setAnimate(true);
  }, []);
  
  const getVerdictInfo = () => {
    if (results.result.includes('VERY LIKELY AI-GENERATED')) {
      return {
        color: 'text-red-400',
        bgColor: 'bg-red-500',
        lightBg: 'bg-red-500/10',
        icon: (
          <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
            <path strokeLinecap="round" strokeLinejoin="round" d="M12 9v2m0 4h.01m-6.938 4h13.856c1.54 0 2.502-1.667 1.732-3L13.732 4c-.77-1.333-2.694-1.333-3.464 0L3.34 16c-.77 1.333.192 3 1.732 3z" />
          </svg>
        )
      };
    } else if (results.result.includes('LIKELY AI-GENERATED')) {
      return {
        color: 'text-orange-400',
        bgColor: 'bg-orange-500',
        lightBg: 'bg-orange-500/10',
        icon: (
          <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
            <path strokeLinecap="round" strokeLinejoin="round" d="M12 9v2m0 4h.01m-6.938 4h13.856c1.54 0 2.502-1.667 1.732-3L13.732 4c-.77-1.333-2.694-1.333-3.464 0L3.34 16c-.77 1.333.192 3 1.732 3z" />
          </svg>
        )
      };
    } else if (results.result.includes('POSSIBLY AI-GENERATED')) {
      return {
        color: 'text-yellow-400',
        bgColor: 'bg-yellow-500',
        lightBg: 'bg-yellow-500/10',
        icon: (
          <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
            <path strokeLinecap="round" strokeLinejoin="round" d="M12 9v2m0 4h.01m-6.938 4h13.856c1.54 0 2.502-1.667 1.732-3L13.732 4c-.77-1.333-2.694-1.333-3.464 0L3.34 16c-.77 1.333.192 3 1.732 3z" />
          </svg>
        )
      }; 
    } else if (results.result.includes('POSSIBLY HUMAN-WRITTEN')) {
      return {
      color: 'text-emerald-400',
      bgColor: 'bg-emerald-500',
      lightBg: 'bg-emerald-500/10',

        icon: (
          <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
            <path strokeLinecap="round" strokeLinejoin="round" d="M12 9v2m0 4h.01m-6.938 4h13.856c1.54 0 2.502-1.667 1.732-3L13.732 4c-.77-1.333-2.694-1.333-3.464 0L3.34 16c-.77 1.333.192 3 1.732 3z" />
          </svg>
        )
      }; 
    } else {
      return {
        color: 'text-green-400',
        bgColor: 'bg-green-500',
        lightBg: 'bg-green-500/10',
        icon: (
          <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
            <path strokeLinecap="round" strokeLinejoin="round" d="M5 13l4 4L19 7" />
          </svg>
        )
      };
    }
  };
  
  const verdictInfo = getVerdictInfo();
  
  return (
    <div className={`rounded-lg overflow-hidden border border-slate-700/80 backdrop-blur-sm transform transition-all ${animate ? 'translate-y-0 opacity-100' : 'translate-y-4 opacity-0'}`}>
      <div className={`p-5 ${verdictInfo.lightBg} border-b border-slate-700/80`}>
        <div className="flex items-center">
          <div className={`w-10 h-10 rounded-full ${verdictInfo.color} ${verdictInfo.lightBg} flex items-center justify-center mr-3`}>
            {verdictInfo.icon}
          </div>
          <div>
            <h2 className={`text-xl font-bold ${verdictInfo.color}`}>
              {results.result}
            </h2>
            <p className="text-slate-400 text-sm mt-1">
              Based on similarity analysis and comparison with AI code patterns
            </p>
          </div>
        </div>
      </div>
      
      <div className="p-5 bg-slate-900/80">    
        <div className="grid md:grid-cols-3 gap-4 mb-6">
          <div className="bg-slate-800/60 rounded-lg p-4 border border-slate-700/50 hover:border-blue-500/30 transition-colors group">
            <div className="flex justify-between items-start mb-2">
              <h4 className="text-slate-400 text-sm">Original Similarity</h4>
              <div className={`text-xs px-1.5 py-0.5 rounded ${results.original_similarity > 0.85 ? 'bg-blue-500/20 text-blue-400' : 'bg-slate-700/80 text-slate-400'}`}>
                Vector Distance
              </div>
            </div>
            <div className="flex items-end">
              <div className="text-2xl font-bold text-white group-hover:text-blue-400 transition-colors">
                {results.original_similarity.toFixed(4)}
              </div>
              <div className="text-slate-500 text-xs ml-2 mb-1">coefficient</div>
            </div>
            <div className="mt-3 h-1.5 bg-slate-700 rounded-full overflow-hidden">
              <div 
                className="h-full bg-gradient-to-r from-blue-600 to-blue-400 rounded-full transition-all duration-1000"
                style={{ width: `${results.original_similarity * 100}%` }}
              ></div>
            </div>
          </div>
          
          <div className="bg-slate-800/60 rounded-lg p-4 border border-slate-700/50 hover:border-blue-500/30 transition-colors group">
            <div className="flex justify-between items-start mb-2">
              <h4 className="text-slate-400 text-sm">AI Generated Similarity</h4>
              <div className={`text-xs px-1.5 py-0.5 rounded ${results.ai_similarity > 0.9 ? 'bg-orange-500/20 text-orange-400' : 'bg-slate-700/80 text-slate-400'}`}>
                Pattern Match
              </div>
            </div>
            <div className="flex items-end">
              <div className="text-2xl font-bold text-white group-hover:text-blue-400 transition-colors">
                {results.ai_similarity.toFixed(4)}
              </div>
              <div className="text-slate-500 text-xs ml-2 mb-1">coefficient</div>
            </div>
            <div className="mt-3 h-1.5 bg-slate-700 rounded-full overflow-hidden">
              <div 
                className="h-full bg-gradient-to-r from-orange-500 to-red-400 rounded-full transition-all duration-1000"
                style={{ width: `${results.ai_similarity * 100}%` }}
              ></div>
            </div>
          </div>
          
          <div className="bg-slate-800/60 rounded-lg p-4 border border-slate-700/50 hover:border-blue-500/30 transition-colors group">
            <div className="flex justify-between items-start mb-2">
              <h4 className="text-slate-400 text-sm">Pattern Difference</h4>
              <div className={`text-xs px-1.5 py-0.5 rounded ${results.difference < 0.05 ? 'bg-red-500/20 text-red-400' : 'bg-slate-700/80 text-slate-400'}`}>
                Critical Factor
              </div>
            </div>
            <div className="flex items-end">
              <div className="text-2xl font-bold text-white group-hover:text-blue-400 transition-colors">
                {results.difference.toFixed(4)}
              </div>
              <div className="text-slate-500 text-xs ml-2 mb-1">variance</div>
            </div>
            <div className="mt-3 h-1.5 bg-slate-700 rounded-full overflow-hidden">
              <div 
                className={`h-full rounded-full transition-all duration-1000 ${results.difference < 0.05 ? 'bg-gradient-to-r from-red-600 to-red-400' : 'bg-gradient-to-r from-yellow-600 to-yellow-400'}`}
                style={{ width: `${Math.min(results.difference * 500, 100)}%` }}
              ></div>
            </div>
          </div>
        </div>
        
        <div className="bg-slate-800/60 p-4 rounded-lg border border-slate-700/50">
          <h4 className="text-slate-300 font-medium mb-2 flex items-center">
            <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4 mr-1 text-blue-400" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
              <path strokeLinecap="round" strokeLinejoin="round" d="M13 16h-1v-4h-1m1-4h.01M21 12a9 9 0 11-18 0 9 9 0 0118 0z" />
            </svg>
            How to interpret
          </h4>
          <ul className="mt-2 space-y-2 text-sm text-slate-400">
            <li className="flex items-start">
              <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4 mr-2 text-blue-400 mt-0.5 flex-shrink-0" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                <path strokeLinecap="round" strokeLinejoin="round" d="M9 12l2 2 4-4m6 2a9 9 0 11-18 0 9 9 0 0118 0z" />
              </svg>
              <span>Higher similarity scores indicate code with consistent patterns and structure</span>
            </li>
            <li className="flex items-start">
              <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4 mr-2 text-blue-400 mt-0.5 flex-shrink-0" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                <path strokeLinecap="round" strokeLinejoin="round" d="M9 12l2 2 4-4m6 2a9 9 0 11-18 0 9 9 0 0118 0z" />
              </svg>
              <span>Smaller pattern differences suggest increased likelihood of AI-generated code</span>
            </li>
            <li className="flex items-start">
              <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4 mr-2 text-blue-400 mt-0.5 flex-shrink-0" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                <path strokeLinecap="round" strokeLinejoin="round" d="M9 12l2 2 4-4m6 2a9 9 0 11-18 0 9 9 0 0118 0z" />
              </svg>
              <span>Human-written code tends to have more variance in structure and style</span>
            </li>
          </ul>
        </div>
        
        <ResultsVisualization results={results} />
      </div>
    </div>
  );
};

export default ResultsDisplay;