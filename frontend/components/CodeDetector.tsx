import React, { useState } from 'react';

interface DetectionResult {
  original_similarity: number;
  ai_similarity: number;
  difference: number;
  result: string;
}

const CodeDetector: React.FC = () => {
  const [code, setCode] = useState<string>('');
  const [loading, setLoading] = useState<boolean>(false);
  const [results, setResults] = useState<DetectionResult | null>(null);
  const [error, setError] = useState<string | null>(null);

  const detectCode = async () => {
    if (!code.trim()) {
      setError('Please enter some code to analyze');
      return;
    }

    setLoading(true);
    setError(null);
    
    try {
      const response = await fetch('http://localhost:3000/detect', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json'
        },
        body: JSON.stringify({ code })
      });
      
      if (!response.ok) {
        throw new Error(`Error: ${response.status}`);
      }
      
      const data = await response.json();
      console.log('Detection results:', data);
      setResults(data);
    } catch (err) {
      console.error('Error detecting code:', err);
      setError('Failed to analyze code. Please make sure the API server is running.');
    } finally {
      setLoading(false);
    }
  };

  // Helper function to get a color based on the verdict
  const getVerdictColor = (verdict: string | undefined) => {
    if (!verdict) return 'text-gray-500';
    
    if (verdict.includes('VERY LIKELY AI-GENERATED')) return 'text-red-600 font-bold';
    if (verdict.includes('LIKELY AI-GENERATED')) return 'text-orange-500 font-bold';
    if (verdict.includes('POSSIBLY AI-GENERATED')) return 'text-yellow-500 font-bold';
    return 'text-green-600 font-bold';
  };

  return (
    <div className="max-w-4xl mx-auto p-6 bg-white rounded-lg shadow-md">
      <h1 className="text-2xl font-bold mb-4 text-gray-800">AI Code Detector</h1>
      <p className="mb-4 text-gray-600">
        Paste your code below to check if it's likely AI-generated
      </p>
      
      <div className="mb-4">
        <textarea 
          className="w-full h-64 p-4 border border-gray-300 rounded-md font-mono text-sm"
          placeholder="Paste your code here..."
          value={code}
          onChange={(e) => setCode(e.target.value)}
        />
      </div>
      
      <button
        className="px-4 py-2 bg-blue-600 text-white rounded-md hover:bg-blue-700 transition-colors"
        onClick={detectCode}
        disabled={loading}
      >
        {loading ? 'Analyzing...' : 'Detect'}
      </button>
      
      {error && (
        <div className="mt-4 p-3 bg-red-100 text-red-700 rounded-md">
          {error}
        </div>
      )}
      
      {results && (
        <div className="mt-6 p-4 border border-gray-300 rounded-md bg-gray-50">
          <h2 className="text-xl font-semibold mb-3 text-gray-800">Detection Results</h2>
          
          <div className="space-y-2">
            <p className="text-gray-700">
              <span className="font-medium">Original Code Similarity:</span> {results.original_similarity.toFixed(4)}
            </p>
            <p className="text-gray-700">
              <span className="font-medium">AI-Generated Code Similarity:</span> {results.ai_similarity.toFixed(4)}
            </p>
            <p className="text-gray-700">
              <span className="font-medium">Difference:</span> {results.difference.toFixed(4)}
            </p>
            <p className={getVerdictColor(results.result)}>
              <span className="font-medium">Verdict:</span> {results.result}
            </p>
          </div>
          
          <div className="mt-4 text-sm text-gray-500">
            <p>The detection is based on similarity patterns between the original code and AI-generated rewrites.</p>
            <p>Lower difference values indicate higher likelihood of AI-generated code.</p>
          </div>
        </div>
      )}
    </div>
  );
};

export default CodeDetector;