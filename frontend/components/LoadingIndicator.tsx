import React from 'react'

interface LoadingIndicatorProps {
  stage: string
}

const LoadingIndicator: React.FC<LoadingIndicatorProps> = ({ stage }) => {
  const stages = [
    { id: 'analyzing', label: 'Analyzing code structure' },
    { id: 'processing', label: 'Processing semantic patterns' },
    { id: 'comparing', label: 'Comparing with AI signatures' },
    { id: 'finished', label: 'Analysis complete' }
  ]
  
  const currentIndex = stages.findIndex(s => s.id === stage)
  
  return (
    <div className="mt-6 p-4 rounded-lg bg-slate-900 border border-slate-700">
      <div className="flex items-center justify-between mb-2">
        <h3 className="text-blue-400 font-medium">Detection in progress</h3>
        <div className="text-slate-400 text-sm animate-pulse">
          <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5 inline mr-1" viewBox="0 0 20 20" fill="currentColor">
            <path fillRule="evenodd" d="M11.3 1.046A1 1 0 0112 2v5h4a1 1 0 01.82 1.573l-7 10A1 1 0 018 18v-5H4a1 1 0 01-.82-1.573l7-10a1 1 0 011.12-.38z" clipRule="evenodd" />
          </svg>
          Processing
        </div>
      </div>
      
      <div className="space-y-4">
        {stages.map((s, index) => (
          <div key={s.id} className="flex items-center">
            <div className={`flex-shrink-0 h-8 w-8 rounded-full flex items-center justify-center ${
              index < currentIndex 
                ? 'bg-green-500 bg-opacity-20 text-green-500' 
                : index === currentIndex 
                  ? 'bg-blue-500 bg-opacity-20 text-blue-500' 
                  : 'bg-slate-700 text-slate-500'
            }`}>
              {index < currentIndex ? (
                <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 20 20" fill="currentColor">
                  <path fillRule="evenodd" d="M16.707 5.293a1 1 0 010 1.414l-8 8a1 1 0 01-1.414 0l-4-4a1 1 0 011.414-1.414L8 12.586l7.293-7.293a1 1 0 011.414 0z" clipRule="evenodd" />
                </svg>
              ) : index === currentIndex ? (
                <div className="h-4 w-4 rounded-full border-2 border-t-transparent border-blue-500 animate-spin"></div>
              ) : (
                <span className="text-xs">{index + 1}</span>
              )}
            </div>
            <div className={`ml-3 ${
              index < currentIndex 
                ? 'text-green-400' 
                : index === currentIndex 
                  ? 'text-blue-400' 
                  : 'text-slate-500'
            }`}>
              {s.label}
              {index === currentIndex && (
                <span className="inline-flex ml-2">
                  <span className="animate-ping delay-0 h-1 w-1 rounded-full bg-blue-400 opacity-75"></span>
                  <span className="animate-ping delay-150 h-1 w-1 rounded-full bg-blue-400 opacity-75 ml-1"></span>
                  <span className="animate-ping delay-300 h-1 w-1 rounded-full bg-blue-400 opacity-75 ml-1"></span>
                </span>
              )}
            </div>
          </div>
        ))}
      </div>
    </div>
  )
}

export default LoadingIndicator