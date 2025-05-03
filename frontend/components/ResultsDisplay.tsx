import React from 'react'

interface ResultsDisplayProps {
  results: {
    original_similarity: number
    ai_similarity: number
    difference: number
    result: string
  }
}

const ResultsDisplay: React.FC<ResultsDisplayProps> = ({ results }) => {
  // Function to determine color based on AI likelihood
  const getVerdictInfo = () => {
    if (results.result.includes('VERY LIKELY AI-GENERATED')) {
      return {
        color: 'text-red-400',
        bgColor: 'bg-red-500',
        fillWidth: '95%',
        icon: (
          <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 20 20" fill="currentColor">
            <path fillRule="evenodd" d="M10 18a8 8 0 100-16 8 8 0 000 16zM8.707 7.293a1 1 0 00-1.414 1.414L8.586 10l-1.293 1.293a1 1 0 101.414 1.414L10 11.414l1.293 1.293a1 1 0 001.414-1.414L11.414 10l1.293-1.293a1 1 0 00-1.414-1.414L10 8.586 8.707 7.293z" clipRule="evenodd" />
          </svg>
        )
      }
    } else if (results.result.includes('LIKELY AI-GENERATED')) {
      return {
        color: 'text-orange-400',
        bgColor: 'bg-orange-500',
        fillWidth: '75%',
        icon: (
          <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 20 20" fill="currentColor">
            <path fillRule="evenodd" d="M8.257 3.099c.765-1.36 2.722-1.36 3.486 0l5.58 9.92c.75 1.334-.213 2.98-1.742 2.98H4.42c-1.53 0-2.493-1.646-1.743-2.98l5.58-9.92zM11 13a1 1 0 11-2 0 1 1 0 012 0zm-1-8a1 1 0 00-1 1v3a1 1 0 002 0V6a1 1 0 00-1-1z" clipRule="evenodd" />
          </svg>
        )
      }
    } else if (results.result.includes('POSSIBLY AI-GENERATED')) {
      return {
        color: 'text-yellow-400',
        bgColor: 'bg-yellow-500',
        fillWidth: '50%',
        icon: (
          <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 20 20" fill="currentColor">
            <path fillRule="evenodd" d="M18 10a8 8 0 11-16 0 8 8 0 0116 0zm-7 4a1 1 0 11-2 0 1 1 0 012 0zm-1-9a1 1 0 00-1 1v4a1 1 0 102 0V6a1 1 0 00-1-1z" clipRule="evenodd" />
          </svg>
        )
      }
    } else {
      return {
        color: 'text-green-400',
        bgColor: 'bg-green-500',
        fillWidth: '15%',
        icon: (
          <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5" viewBox="0 0 20 20" fill="currentColor">
            <path fillRule="evenodd" d="M10 18a8 8 0 100-16 8 8 0 000 16zm3.707-9.293a1 1 0 00-1.414-1.414L9 10.586 7.707 9.293a1 1 0 00-1.414 1.414l2 2a1 1 0 001.414 0l4-4z" clipRule="evenodd" />
          </svg>
        )
      }
    }
  }
  
  const verdictInfo = getVerdictInfo()
  
  return (
    <div className="rounded-lg bg-slate-900 border border-slate-700 overflow-hidden">
      <div className="p-5 border-b border-slate-700">
        <h2 className="text-lg text-white font-bold">Analysis Results</h2>
      </div>
      
      <div className="p-5 space-y-5">
        {/* AI Detection Verdict */}
        <div className="mb-6 flex items-center">
          <div className={`w-10 h-10 rounded-full ${verdictInfo.color} bg-opacity-20 flex items-center justify-center mr-3`}>
            {verdictInfo.icon}
          </div>
          <div>
            <h3 className={`text-xl font-bold ${verdictInfo.color}`}>
              {results.result}
            </h3>
            <p className="text-slate-400 text-sm mt-1">
              Based on similarity analysis and comparison with AI code patterns
            </p>
          </div>
        </div>
        
        {/* AI Likelihood Meter */}
        <div className="mb-6">
          <div className="flex items-center justify-between mb-2">
            <h4 className="text-slate-300 font-medium">AI Likelihood</h4>
            <span className={`${verdictInfo.color} font-bold`}>
              {Math.round((1 - results.difference) * 100)}%
            </span>
          </div>
          <div className="h-3 bg-slate-800 rounded-full overflow-hidden">
            <div 
              className={`h-full ${verdictInfo.bgColor} rounded-full`} 
              style={{ width: verdictInfo.fillWidth }}
            ></div>
          </div>
        </div>
        
        {/* Detailed Metrics */}
        <div className="grid md:grid-cols-3 gap-4">
          {/* Similarity Scores */}
          <div className="bg-slate-800 rounded-lg p-4">
            <h4 className="text-slate-400 text-sm mb-2">Original Similarity</h4>
            <div className="text-xl font-bold text-white">
              {results.original_similarity.toFixed(4)}
            </div>
          </div>
          
          <div className="bg-slate-800 rounded-lg p-4">
            <h4 className="text-slate-400 text-sm mb-2">AI Generated Similarity</h4>
            <div className="text-xl font-bold text-white">
              {results.ai_similarity.toFixed(4)}
            </div>
          </div>
          
          <div className="bg-slate-800 rounded-lg p-4">
            <h4 className="text-slate-400 text-sm mb-2">Pattern Difference</h4>
            <div className="text-xl font-bold text-white">
              {results.difference.toFixed(4)}
            </div>
          </div>
        </div>
        
        <div className="mt-4 text-sm text-slate-400 bg-slate-800 p-4 rounded-lg">
          <h4 className="text-slate-300 font-medium mb-2">How to interpret</h4>
          <ul className="list-disc list-inside space-y-1">
            <li>Higher similarity scores indicate code with consistent patterns</li>
            <li>Smaller difference values suggest increased likelihood of AI-generated code</li>
            <li>Human-written code tends to have more variance in structure and style</li>
            <li>Click on the "Code Diff" tab to see a comparison</li>
          </ul>
        </div>
      </div>
    </div>
  )
}

export default ResultsDisplay