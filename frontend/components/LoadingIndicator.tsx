import React, { useEffect, useState } from 'react'

interface LoadingIndicatorProps {
  stage: string
}

const LoadingIndicator: React.FC<LoadingIndicatorProps> = ({ stage }) => {
  const [progress, setProgress] = useState(0);
  
  const stages = [
    { id: 'analyzing', label: 'Analyzing code structure', description: 'Parsing and tokenizing code patterns' },
    { id: 'processing', label: 'Processing semantic patterns', description: 'Evaluating code organization and style' },
    { id: 'comparing', label: 'Comparing with AI signatures', description: 'Matching against known AI patterns' },
    { id: 'finished', label: 'Analysis complete', description: 'Generating final report' }
  ]
  
  const currentIndex = stages.findIndex(s => s.id === stage)
  
  useEffect(() => {
    // Update progress bar based on current stage
    const newProgress = ((currentIndex + 1) / stages.length) * 100;
    
    // Animate progress
    const interval = setInterval(() => {
      setProgress(prev => {
        if (prev < newProgress) {
          return prev + 2;
        }
        clearInterval(interval);
        return prev;
      });
    }, 20);
    
    return () => clearInterval(interval);
  }, [currentIndex, stages.length]);
  
  return (
    <div className="mt-6 p-5 rounded-lg bg-slate-900/80 border border-slate-700/80 backdrop-blur-sm shadow-lg transition-all duration-500">
      <div className="flex items-center justify-between mb-3">
        <h3 className="text-blue-400 font-medium flex items-center">
          <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5 mr-2" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
            <path strokeLinecap="round" strokeLinejoin="round" d="M13 10V3L4 14h7v7l9-11h-7z" />
          </svg>
          Detection in progress
        </h3>
        <div className="text-slate-400 text-sm flex items-center">
          <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4 mr-1 animate-pulse text-blue-500" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
            <path strokeLinecap="round" strokeLinejoin="round" d="M5.636 18.364a9 9 0 010-12.728m12.728 0a9 9 0 010 12.728m-9.9-2.829a5 5 0 010-7.07m7.072 0a5 5 0 010 7.07M13 12a1 1 0 11-2 0 1 1 0 012 0z" />
          </svg>
          Processing
        </div>
      </div>
      
      {/* Progress bar */}
      <div className="w-full h-1.5 bg-slate-700 rounded-full mb-6 overflow-hidden">
        <div 
          className="h-full bg-gradient-to-r from-blue-600 to-blue-400 rounded-full transition-all duration-300"
          style={{ width: `${progress}%` }}
        ></div>
      </div>
      
      <div className="space-y-6">
        {stages.map((s, index) => (
          <div key={s.id} className="flex items-start">
            <div className={`flex-shrink-0 h-8 w-8 rounded-full flex items-center justify-center ${
              index < currentIndex 
                ? 'bg-green-500/20 text-green-500' 
                : index === currentIndex 
                  ? 'bg-blue-500/20 text-blue-500' 
                  : 'bg-slate-700/50 text-slate-500'
            }`}>
              {index < currentIndex ? (
                <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                  <path strokeLinecap="round" strokeLinejoin="round" d="M5 13l4 4L19 7" />
                </svg>
              ) : index === currentIndex ? (
                <div className="h-4 w-4 rounded-full border-2 border-t-transparent border-blue-500 animate-spin"></div>
              ) : (
                <span className="text-xs">{index + 1}</span>
              )}
            </div>
            <div className="ml-4 flex-1">
              <p className={`font-medium ${
                index < currentIndex 
                  ? 'text-green-400' 
                  : index === currentIndex 
                    ? 'text-blue-400' 
                    : 'text-slate-500'
              }`}>
                {s.label}
                {index === currentIndex && (
                  <span className="inline-flex ml-2">
                    <span className="animate-ping h-1 w-1 rounded-full bg-blue-400 opacity-75"></span>
                    <span className="animate-ping delay-150 h-1 w-1 rounded-full bg-blue-400 opacity-75 ml-1"></span>
                    <span className="animate-ping delay-300 h-1 w-1 rounded-full bg-blue-400 opacity-75 ml-1"></span>
                  </span>
                )}
              </p>
              <p className={`text-sm ${
                index < currentIndex 
                  ? 'text-slate-400' 
                  : index === currentIndex 
                    ? 'text-slate-300' 
                    : 'text-slate-600'
              }`}>
                {s.description}
              </p>
            </div>
          </div>
        ))}
      </div>
      
      {/* Animated particles for visual flair */}
      <div className="relative h-24 mt-6 overflow-hidden rounded-md bg-slate-800/50">
        <div className="absolute inset-0 opacity-10">
          <div className="absolute w-1 h-1 bg-blue-400 rounded-full animate-pulse" style={{top: '20%', left: '30%', animationDelay: '0.5s'}}></div>
          <div className="absolute w-1 h-1 bg-blue-400 rounded-full animate-pulse" style={{top: '70%', left: '40%', animationDelay: '0.7s'}}></div>
          <div className="absolute w-1 h-1 bg-blue-400 rounded-full animate-pulse" style={{top: '40%', left: '60%', animationDelay: '0.2s'}}></div>
          <div className="absolute w-1 h-1 bg-blue-400 rounded-full animate-pulse" style={{top: '30%', left: '70%', animationDelay: '1s'}}></div>
          <div className="absolute w-1 h-1 bg-blue-400 rounded-full animate-pulse" style={{top: '60%', left: '20%', animationDelay: '0.3s'}}></div>
        </div>
        <div className="flex items-center justify-center h-full">
          <p className="text-sm text-slate-500">Analyzing code patterns and structures...</p>
        </div>
      </div>
    </div>
  )
}

export default LoadingIndicator;