import React, { useState } from 'react'
import CodeEditor from './CodeEditor'
import ResultsDisplay from './ResultsDisplay'
import LoadingIndicator from './LoadingIndicator'
import DiffViewer from './DIffViewer'

interface DetectionResult {
  original_similarity: number;
  ai_similarity: number;
  difference: number;
  result: string;
}

const CodeDetectionPage: React.FC = () => {
  const [code, setCode] = useState<string>('')
  const [loading, setLoading] = useState<boolean>(false)
  const [stage, setStage] = useState<string>('idle') // idle, analyzing, comparing, finished
  const [results, setResults] = useState<DetectionResult | null>(null)
  const [aiGeneratedCode, setAiGeneratedCode] = useState<string>('')
  const [error, setError] = useState<string | null>(null)
  const [activeTab, setActiveTab] = useState<'editor' | 'diff'>('editor')

  const detectCode = async () => {
    if (!code.trim()) {
      setError('Please enter some code to analyze')
      return
    }

    setLoading(true)
    setError(null)
    setStage('analyzing')
    
    // Simulate different stages of processing (replace with real API call)
    setTimeout(() => setStage('processing'), 1500)
    setTimeout(() => setStage('comparing'), 3000)
    
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
      // For demo purposes: generate a slightly modified version of the code
      // In a real app, this would come from the API
      setAiGeneratedCode(generateSampleAICode(code))
      setTimeout(() => {
        setStage('finished')
        setActiveTab('diff')
      }, 1000)
    } catch (err) {
      console.error('Error detecting code:', err)
      setError('Failed to analyze code. Please make sure the API server is running.')
      setStage('idle')
    } finally {
      setLoading(false)
    }
  }

  // Helper function to generate a sample "AI-generated" code for demo purposes
  const generateSampleAICode = (originalCode: string): string => {
    // This is just a simple demo transformation - replace with real data from API
    return originalCode
      .split('\\n')
      .map(line => {
        // Add some comments and reformatting to simulate AI changes
        if (line.trim().startsWith('//')) return line
        if (line.trim().startsWith('function') || line.trim().startsWith('const ')) {
          return line + ' // AI optimized function'
        }
        if (line.includes('if') || line.includes('for')) {
          return line + ' // AI added control flow'
        }
        return line
      })
      .join('\\n')
  }

  return (
    <div className="bg-slate-800 rounded-lg shadow-xl overflow-hidden">
      <div className="border-b border-slate-700 p-4">
        <h1 className="text-2xl font-bold text-white">AI Code Detection</h1>
        <p className="text-slate-400 mt-1">
          Detect if code was written by AI or humans using semantic analysis
        </p>
      </div>

      <div className="flex border-b border-slate-700">
        <button 
          className={`py-3 px-6 font-medium focus:outline-none ${
            activeTab === 'editor' 
              ? 'text-blue-400 border-b-2 border-blue-400' 
              : 'text-slate-400 hover:text-slate-300'
          }`}
          onClick={() => setActiveTab('editor')}
        >
          Code Editor
        </button>
        <button 
          className={`py-3 px-6 font-medium focus:outline-none ${
            activeTab === 'diff' 
              ? 'text-blue-400 border-b-2 border-blue-400' 
              : 'text-slate-400 hover:text-slate-300'
          }`}
          onClick={() => setActiveTab('diff')}
          disabled={!results}
        >
          Code Diff
        </button>
      </div>

      <div className="p-6">
        {activeTab === 'editor' ? (
          <>
            <CodeEditor 
              code={code} 
              onChange={setCode} 
              placeholder="Paste your code here or start typing..."
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
          </>
        ) : (
          <DiffViewer originalCode={code} aiGeneratedCode={aiGeneratedCode} />
        )}
      </div>
    </div>
  )
}

export default CodeDetectionPage