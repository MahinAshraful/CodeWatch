import React, { useState } from 'react'
import CodeEditor from './CodeEditor'
import ResultsDisplay from './ResultsDisplay'
import LoadingIndicator from './LoadingIndicator'

interface DetectionResult {
  original_similarity: number;
  ai_similarity: number;
  difference: number;
  result: string;
}

const CodeDetectionPage: React.FC = () => {
  const [code, setCode] = useState<string>('')
  const [loading, setLoading] = useState<boolean>(false)
  const [stage, setStage] = useState<string>('idle') // idle, analyzing, processing, comparing, finished
  const [results, setResults] = useState<DetectionResult | null>(null)
  const [error, setError] = useState<string | null>(null)
  const [language, setLanguage] = useState<string>('javascript')

  const detectCode = async () => {
    if (!code.trim()) {
      setError('Please enter some code to analyze')
      return
    }

    setLoading(true)
    setError(null)
    setStage('analyzing')
    
    // Simulate different stages of processing with real API call
    setTimeout(() => setStage('processing'), 1000)
    setTimeout(() => setStage('comparing'), 2000)
    
    try {
      const response = await fetch('http://localhost:3000/detect', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify({ code })
      })
      
      if (!response.ok) {
        throw new Error(`Error: ${response.status}`)
      }
      
      const data = await response.json()
      console.log('Detection results:', data)
      setResults(data)
      setStage('finished')
      
    } catch (err) {
      console.error('Error detecting code:', err)
      setError('Failed to analyze code. Please make sure the API server is running.')
      setStage('idle')
    } finally {
      setLoading(false)
    }
  }

  // Handle language change
  const handleLanguageChange = (newLanguage: string) => {
    setLanguage(newLanguage)
  }

  return (
    <div className="bg-slate-800 rounded-lg shadow-xl overflow-hidden">
      <div className="border-b border-slate-700 p-4">
        <h1 className="text-2xl font-bold text-white">AI Code Detection</h1>
        <p className="text-slate-400 mt-1">
          Detect if code was written by AI or humans using semantic analysis
        </p>
      </div>

      <div className="p-6">
        <CodeEditor 
          code={code} 
          onChange={setCode} 
          placeholder="Paste your code here or start typing..."
          language={language}
        />
        
        <div className="mt-6 flex flex-col sm:flex-row sm:items-center gap-3">
          <button
            className="px-6 py-3 bg-blue-600 hover:bg-blue-700 text-white font-medium rounded-md transition-colors focus:outline-none focus:ring-2 focus:ring-blue-500 focus:ring-opacity-50 disabled:opacity-50 disabled:cursor-not-allowed"
            onClick={detectCode}
            disabled={loading || !code.trim()}
          >
            {loading ? 'Analyzing...' : 'Detect AI Code'}
          </button>
          
          {error && (
            <div className="mt-2 sm:mt-0 px-4 py-2 bg-red-500 bg-opacity-20 border border-red-500 border-opacity-30 rounded-md text-red-400">
              {error}
            </div>
          )}
        </div>
        
        {loading && <LoadingIndicator stage={stage} />}
        
        {results && !loading && (
          <div className="mt-6">
            <ResultsDisplay results={results} />
          </div>
        )}
      </div>
    </div>
  )
}

export default CodeDetectionPage