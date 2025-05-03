import React, { useState, useEffect } from 'react'

interface CodeEditorProps {
  code: string
  onChange: (code: string) => void
  placeholder?: string
}

const CodeEditor: React.FC<CodeEditorProps> = ({ code, onChange, placeholder = 'Type your code...' }) => {
  const [lines, setLines] = useState<number[]>([])
  
  // Update line numbers whenever code changes
  useEffect(() => {
    const lineCount = code.split('\n').length
    setLines(Array.from({ length: lineCount }, (_, i) => i + 1))
  }, [code])

  const handleKeyDown = (e: React.KeyboardEvent<HTMLTextAreaElement>) => {
    // Handle tab key to insert spaces instead of changing focus
    if (e.key === 'Tab') {
      e.preventDefault()
      
      const target = e.target as HTMLTextAreaElement
      const start = target.selectionStart
      const end = target.selectionEnd
      
      // Insert 2 spaces at cursor position
      const newText = code.substring(0, start) + '  ' + code.substring(end)
      onChange(newText)
      
      // Move cursor position after the inserted tab
      setTimeout(() => {
        target.selectionStart = target.selectionEnd = start + 2
      }, 0)
    }
  }

  return (
    <div className="rounded-lg overflow-hidden bg-slate-900 border border-slate-700 shadow-lg">
      <div className="flex items-center space-x-2 p-2 bg-slate-800 border-b border-slate-700">
        <div className="flex space-x-1">
          <div className="w-3 h-3 rounded-full bg-red-500"></div>
          <div className="w-3 h-3 rounded-full bg-yellow-500"></div>
          <div className="w-3 h-3 rounded-full bg-green-500"></div>
        </div>
        <div className="text-xs text-slate-400">code-editor.js</div>
      </div>
      <div className="relative flex">
        {/* Line numbers */}
        <div className="hidden sm:block py-3 px-2 text-right bg-slate-800 border-r border-slate-700 select-none">
          {lines.map(num => (
            <div key={num} className="text-xs text-slate-500 font-mono leading-5">{num}</div>
          ))}
          {/* Add an extra line for when user is at the end */}
          <div className="text-xs text-slate-500 font-mono leading-5">{lines.length + 1}</div>
        </div>
        
        {/* Code editor textarea */}
        <textarea
          value={code}
          onChange={(e) => onChange(e.target.value)}
          onKeyDown={handleKeyDown}
          placeholder={placeholder}
          className="flex-1 bg-slate-900 text-slate-200 font-mono text-sm p-3 resize-none focus:outline-none min-h-[400px] w-full"
          spellCheck="false"
          autoComplete="off"
          autoCorrect="off"
          autoCapitalize="off"
        />
      </div>
    </div>
  )
}

export default CodeEditor