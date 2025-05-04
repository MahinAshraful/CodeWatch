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
  const [activeTab, setActiveTab] = useState<string>('editor') // 'editor' or 'results'

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
        body: JSON.stringify({ 
          code,
          language // Send the detected language to the backend
        })
      })
      
      if (!response.ok) {
        throw new Error(`Error: ${response.status}`)
      }
      
      const data = await response.json()
      console.log('Detection results:', data)
      setResults(data)
      setStage('finished')
      setActiveTab('results') // Auto switch to results tab
      
    } catch (err) {
      console.error('Error detecting code:', err)
      setError('Failed to analyze code. Please make sure the API server is running.')
      setStage('idle')
    } finally {
      setLoading(false)
    }
  }

  // Handle language change from CodeEditor
  const handleLanguageChange = (newLanguage: string) => {
    setLanguage(newLanguage)
  }

  return (
    <div className="bg-slate-800/60 backdrop-blur-sm rounded-xl shadow-xl overflow-hidden border border-slate-700/50 transform transition-all hover:shadow-blue-900/5">
      {/* Tabs */}
      <div className="border-b border-slate-700/50 flex">
        <button 
          className={`py-4 px-6 font-medium text-sm focus:outline-none transition-all duration-300 flex items-center ${
            activeTab === 'editor' 
              ? 'text-blue-400 border-b-2 border-blue-500 bg-slate-800/70' 
              : 'text-slate-400 hover:text-slate-200 hover:bg-slate-700/30'
          }`}
          onClick={() => setActiveTab('editor')}
        >
          <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4 mr-2" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
            <path strokeLinecap="round" strokeLinejoin="round" d="M10 20l4-16m4 4l4 4-4 4M6 16l-4-4 4-4" />
          </svg>
          Code Editor
        </button>
        <button 
          className={`py-4 px-6 font-medium text-sm focus:outline-none transition-all duration-300 flex items-center ${
            activeTab === 'results' 
              ? 'text-blue-400 border-b-2 border-blue-500 bg-slate-800/70' 
              : 'text-slate-400 hover:text-slate-200 hover:bg-slate-700/30'
          }`}
          onClick={() => setActiveTab('results')}
          disabled={!results}
        >
          <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4 mr-2" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
            <path strokeLinecap="round" strokeLinejoin="round" d="M9 19v-6a2 2 0 00-2-2H5a2 2 0 00-2 2v6a2 2 0 002 2h2a2 2 0 002-2zm0 0V9a2 2 0 012-2h2a2 2 0 012 2v10m-6 0a2 2 0 002 2h2a2 2 0 002-2m0 0V5a2 2 0 012-2h2a2 2 0 012 2v14a2 2 0 01-2 2h-2a2 2 0 01-2-2z" />
          </svg>
          Results {results && <span className="ml-2 inline-flex items-center px-2 py-0.5 rounded-full text-xs font-medium bg-blue-600/20 text-blue-400">Available</span>}
        </button>
      </div>

      <div className="p-6">
        <div className="mb-4">
          <h1 className="text-2xl font-bold text-white flex items-center">
            <svg xmlns="http://www.w3.org/2000/svg" className="h-6 w-6 text-blue-400 mr-2" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
              <path strokeLinecap="round" strokeLinejoin="round" d="M12 15v2m-6 4h12a2 2 0 002-2v-6a2 2 0 00-2-2H6a2 2 0 00-2 2v6a2 2 0 002 2zm10-10V7a4 4 0 00-8 0v4h8z" />
            </svg>
            AI Code Detector
          </h1>
          <p className="text-slate-400 mt-1">
            Detect if code was written by AI or humans using semantic analysis
          </p>
        </div>

        {activeTab === 'editor' && (
          <>
            <CodeEditor 
              code={code} 
              onChange={setCode} 
              placeholder="Paste your code here or start typing..."
              language={language}
              onLanguageChange={handleLanguageChange}
            />
            
            {language && (
              <div className="mt-3 text-sm text-slate-400 flex items-center">
                <svg xmlns="http://www.w3.org/2000/svg" className="h-4 w-4 mr-1 text-blue-400" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                  <path strokeLinecap="round" strokeLinejoin="round" d="M13 16h-1v-4h-1m1-4h.01M21 12a9 9 0 11-18 0 9 9 0 0118 0z" />
                </svg>
                Language detected: <span className="font-medium text-blue-400 ml-1">{language.charAt(0).toUpperCase() + language.slice(1)}</span>
              </div>
            )}
            
            <div className="mt-6 flex flex-col sm:flex-row sm:items-center gap-3">
              <button
                className="px-5 py-3 bg-blue-600 hover:bg-blue-700 text-white font-medium rounded-md transition-all duration-300 focus:outline-none focus:ring-2 focus:ring-blue-500 focus:ring-opacity-50 disabled:opacity-50 disabled:cursor-not-allowed shadow-md hover:shadow-lg flex items-center justify-center group"
                onClick={detectCode}
                disabled={loading || !code.trim()}
              >
                {loading ? (
                  <span className="flex items-center">
                    <svg className="animate-spin -ml-1 mr-2 h-4 w-4 text-white" xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24">
                      <circle className="opacity-25" cx="12" cy="12" r="10" stroke="currentColor" strokeWidth="4"></circle>
                      <path className="opacity-75" fill="currentColor" d="M4 12a8 8 0 018-8V0C5.373 0 0 5.373 0 12h4zm2 5.291A7.962 7.962 0 014 12H0c0 3.042 1.135 5.824 3 7.938l3-2.647z"></path>
                    </svg>
                    Analyzing...
                  </span>
                ) : (
                  <span className="flex items-center">
                    <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5 mr-2 group-hover:animate-pulse" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                      <path strokeLinecap="round" strokeLinejoin="round" d="M5 3v4M3 5h4M6 17v4m-2-2h4m5-16l2.286 6.857L21 12l-5.714 2.143L13 21l-2.286-6.857L5 12l5.714-2.143L13 3z" />
                    </svg>
                    Detect AI Code
                  </span>
                )}
              </button>
              
              {error && (
                <div className="mt-2 sm:mt-0 px-4 py-2 bg-red-500/10 border border-red-500/30 rounded-md text-red-400 animate-pulse">
                  <div className="flex items-center">
                    <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5 mr-2 flex-shrink-0" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                      <path strokeLinecap="round" strokeLinejoin="round" d="M12 8v4m0 4h.01M21 12a9 9 0 11-18 0 9 9 0 0118 0z" />
                    </svg>
                    {error}
                  </div>
                </div>
              )}
            </div>
            
            {loading && <LoadingIndicator stage={stage} />}
          </>
        )}
        
        {activeTab === 'results' && results && (
          <div className="mt-4">
            <ResultsDisplay results={results} />
          </div>
        )}
      </div>
    </div>
  )
}

export default CodeDetectionPage;