import React, { useState, useEffect } from 'react'

interface DiffViewerProps {
  originalCode: string
  aiGeneratedCode: string
}

interface DiffLine {
  lineNumber: number
  content: string
  type: 'unchanged' | 'added' | 'removed' | 'modified'
  highlights?: Array<{ start: number; end: number }>
}

const DiffViewer: React.FC<DiffViewerProps> = ({ originalCode, aiGeneratedCode }) => {
  const [diffLines, setDiffLines] = useState<DiffLine[]>([])
  
  useEffect(() => {
    // Simple diff algorithm for demonstration purposes
    // In a real app, you would use a proper diff library
    const original = originalCode.split('\n')
    const generated = aiGeneratedCode.split('\n')
    
    const result: DiffLine[] = []
    
    // Find longest common subsequence or use a simple line-by-line comparison
    const maxLines = Math.max(original.length, generated.length)
    
    for (let i = 0; i < maxLines; i++) {
      const originalLine = original[i] || ''
      const generatedLine = generated[i] || ''
      
      if (!originalLine && generatedLine) {
        // Added line
        result.push({
          lineNumber: i + 1,
          content: generatedLine,
          type: 'added'
        })
      } else if (originalLine && !generatedLine) {
        // Removed line
        result.push({
          lineNumber: i + 1,
          content: originalLine,
          type: 'removed'
        })
      } else if (originalLine !== generatedLine) {
        // Modified line - find the specific changes
        result.push({
          lineNumber: i + 1,
          content: generatedLine,
          type: 'modified',
          highlights: findTextDifferences(originalLine, generatedLine)
        })
      } else {
        // Unchanged line
        result.push({
          lineNumber: i + 1,
          content: originalLine,
          type: 'unchanged'
        })
      }
    }
    
    setDiffLines(result)
  }, [originalCode, aiGeneratedCode])
  
  // Very simplified algorithm to find text differences for highlighting
  const findTextDifferences = (original: string, modified: string): Array<{ start: number; end: number }> => {
    const highlights: Array<{ start: number; end: number }> = []
    
    // Find comment additions (very simplified approach)
    if (modified.includes('//') && !original.includes('//')) {
      const commentIndex = modified.indexOf('//')
      highlights.push({
        start: commentIndex,
        end: modified.length
      })
    }
    
    // In a real app, you would use a proper text diff algorithm here
    // This is just a simple demo to show the concept
    
    return highlights
  }
  
  return (
    <div className="rounded-lg overflow-hidden bg-slate-900 border border-slate-700 shadow-lg">
      <div className="flex items-center justify-between p-3 bg-slate-800 border-b border-slate-700">
        <div className="text-slate-300 font-medium">Code Comparison</div>
        <div className="flex text-xs">
          <div className="flex items-center mr-4">
            <span className="w-3 h-3 rounded-full bg-green-500 mr-1"></span>
            <span className="text-slate-400">Added</span>
          </div>
          <div className="flex items-center mr-4">
            <span className="w-3 h-3 rounded-full bg-red-500 mr-1"></span>
            <span className="text-slate-400">Removed</span>
          </div>
          <div className="flex items-center">
            <span className="w-3 h-3 rounded-full bg-yellow-500 mr-1"></span>
            <span className="text-slate-400">Modified</span>
          </div>
        </div>
      </div>
      
      <div className="overflow-x-auto">
        <table className="w-full">
          <tbody>
            {diffLines.map((line, index) => (
              <tr 
                key={index} 
                className={`
                  hover:bg-slate-800 
                  ${line.type === 'added' ? 'bg-green-900 bg-opacity-20' : ''}
                  ${line.type === 'removed' ? 'bg-red-900 bg-opacity-20' : ''}
                  ${line.type === 'modified' ? 'bg-yellow-900 bg-opacity-20' : ''}
                `}
              >
                <td className="text-right py-1 pl-3 pr-2 text-xs text-slate-500 font-mono select-none border-r border-slate-700 w-10">
                  {line.lineNumber}
                </td>
                <td 
                  className={`py-1 pl-4 pr-3 font-mono text-sm whitespace-pre ${
                    line.type === 'added' ? 'text-green-400' : 
                    line.type === 'removed' ? 'text-red-400' : 
                    line.type === 'modified' ? 'text-yellow-400' : 
                    'text-slate-300'
                  }`}
                >
                  {line.highlights ? (
                    <>
                      {line.content.substring(0, line.highlights[0]?.start)}
                      <span className="bg-yellow-900 bg-opacity-30 rounded px-1">
                        {line.content.substring(line.highlights[0]?.start, line.highlights[0]?.end)}
                      </span>
                      {line.content.substring(line.highlights[0]?.end)}
                    </>
                  ) : (
                    line.content
                  )}
                </td>
              </tr>
            ))}
          </tbody>
        </table>
      </div>
      
      {diffLines.length === 0 && (
        <div className="p-6 text-center text-slate-400">
          No code to compare. Please enter code and run detection first.
        </div>
      )}
    </div>
  )
}

export default DiffViewer