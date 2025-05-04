import React, { useState, useEffect, useRef } from 'react'
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter'
import { vscDarkPlus } from 'react-syntax-highlighter/dist/esm/styles/prism'

interface CodeEditorProps {
  code: string
  onChange: (code: string) => void
  placeholder?: string
  language: string
  onLanguageChange?: (language: string) => void
}

const CodeEditor: React.FC<CodeEditorProps> = ({ 
  code, 
  onChange, 
  placeholder = 'Type your code...', 
  language,
  onLanguageChange 
}) => {
  const [lines, setLines] = useState<number[]>([])
  const [selectedLanguage, setSelectedLanguage] = useState(language)
  const [isLanguageAutoDetected, setIsLanguageAutoDetected] = useState(false)
  const [isFocused, setIsFocused] = useState(false)
  const editorRef = useRef<HTMLDivElement>(null)
  
  // Calculate line numbers
  useEffect(() => {
    const lineCount = code.split('\n').length
    setLines(Array.from({ length: lineCount }, (_, i) => i + 1))
    
    // Auto-detect language when code changes significantly
    if (code.length > 10 && !isLanguageAutoDetected) {
      const detectedLang = detectLanguage(code)
      if (detectedLang && detectedLang !== selectedLanguage) {
        setSelectedLanguage(detectedLang)
        setIsLanguageAutoDetected(true)
        if (onLanguageChange) {
          onLanguageChange(detectedLang)
        }
      }
    }
  }, [code, selectedLanguage, isLanguageAutoDetected, onLanguageChange])

  // Add subtle cursor pulse effect when focused
  useEffect(() => {
    if (editorRef.current) {
      if (isFocused) {
        editorRef.current.classList.add('ring-1', 'ring-blue-500/50')
      } else {
        editorRef.current.classList.remove('ring-1', 'ring-blue-500/50')
      }
    }
  }, [isFocused])

  const detectLanguage = (codeString: string): string => {
    // Simple language detection based on file extensions, keywords, and syntax patterns
    const patterns = {
      javascript: {
        keywords: ['const', 'let', 'var', 'function', 'return', 'import', 'export', 'from', '=>', 'console.log'],
        patterns: [/const\s+\w+\s*=/, /let\s+\w+\s*=/, /import\s+.*\s+from\s+['"]/, /export\s+default/, /\)\s*=>\s*{/]
      },
      typescript: {
        keywords: ['interface', 'type', 'namespace', 'enum', '<T>', 'extends', 'implements', ':string', ':number', ':boolean'],
        patterns: [/interface\s+\w+/, /type\s+\w+\s*=/, /(:\s*string|:\s*number|:\s*boolean)/, /<\w+>/]
      },
      python: {
        keywords: ['def', 'import', 'from', 'class', 'if __name__ == "__main__"', 'print(', 'self', '__init__'],
        patterns: [/def\s+\w+\s*\(/, /class\s+\w+\s*:/, /import\s+\w+/, /if\s+__name__\s*==\s*["']__main__["']/, /print\s*\(/]
      },
      java: {
        keywords: ['public', 'class', 'static', 'void', 'main', 'String[]', 'extends', 'implements', 'new'],
        patterns: [/public\s+class/, /public\s+static\s+void\s+main/, /String\[\]\s+args/, /\w+\s+extends\s+\w+/]
      },
      cpp: {
        keywords: ['#include', 'int main', 'std::', 'cout', 'cin', 'vector<', 'template<'],
        patterns: [/#include\s*<\w+>/, /int\s+main\s*\(/, /std::\w+/, /cout\s*<</, /cin\s*>>/]
      },
      html: {
        keywords: ['<!DOCTYPE', '<html', '<head', '<body', '<div', '<span', '<p>', '</p>', '<a href'],
        patterns: [/<\/?[a-z][\s\S]*>/i, /<html.*>/i, /<div.*>/i, /<head>.*<\/head>/is]
      },
      css: {
        keywords: ['body {', 'margin:', 'padding:', 'font-family:', '@media', 'color:', '#'],
        patterns: [/\s*{\s*[\w-]+\s*:\s*[^;]+;/, /@media\s+/, /\w+\s*{\s*\w+\s*:\s*[^;]+;/]
      }
    }

    // Score each language based on matching patterns and keywords
    const scores: Record<string, number> = {}
    
    Object.keys(patterns).forEach(lang => {
      const langPatterns = patterns[lang as keyof typeof patterns]
      
      // Score based on keywords
      langPatterns.keywords.forEach(keyword => {
        if (codeString.includes(keyword)) {
          scores[lang] = (scores[lang] || 0) + 1
        }
      })
      
      // Score based on regex patterns
      langPatterns.patterns.forEach(pattern => {
        if (pattern.test(codeString)) {
          scores[lang] = (scores[lang] || 0) + 2 // Patterns are weighted more heavily
        }
      })
    })
    
    // Check for special cases like shebang lines for scripts
    if (codeString.startsWith('#!/usr/bin/env python') || codeString.startsWith('#!/usr/bin/python')) {
      scores['python'] = (scores['python'] || 0) + 10
    }
    if (codeString.startsWith('#!/usr/bin/env node') || codeString.startsWith('#!/usr/bin/node')) {
      scores['javascript'] = (scores['javascript'] || 0) + 10
    }
    
    // Find the language with the highest score
    let bestMatch = ''
    let highestScore = 0
    
    Object.keys(scores).forEach(lang => {
      if (scores[lang] > highestScore) {
        highestScore = scores[lang]
        bestMatch = lang
      }
    })
    
    // Only return a detected language if the score is above a threshold
    return highestScore >= 3 ? bestMatch : ''
  }

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

  const handleLanguageChange = (e: React.ChangeEvent<HTMLSelectElement>) => {
    const newLanguage = e.target.value
    setSelectedLanguage(newLanguage)
    setIsLanguageAutoDetected(true) // User has manually selected a language
    if (onLanguageChange) {
      onLanguageChange(newLanguage)
    }
  }

  const handlePaste = (e: React.ClipboardEvent<HTMLTextAreaElement>) => {
    // Reset auto-detection flag when new code is pasted
    setIsLanguageAutoDetected(false)
  }

  return (
    <div 
      ref={editorRef}
      className="rounded-lg overflow-hidden bg-slate-900 border border-slate-700/80 shadow-lg transition-all duration-300 hover:shadow-blue-900/10"
    >
      <div className="flex items-center justify-between p-2 bg-slate-800/80 border-b border-slate-700/80">
        <div className="flex space-x-1.5">
          <div className="w-3 h-3 rounded-full bg-red-500 group cursor-pointer relative">
            <span className="absolute -top-8 left-1/2 -translate-x-1/2 px-2 py-1 bg-slate-800 text-xs text-slate-300 rounded opacity-0 group-hover:opacity-100 transition-opacity">Close</span>
          </div>
          <div className="w-3 h-3 rounded-full bg-yellow-500 group cursor-pointer relative">
            <span className="absolute -top-8 left-1/2 -translate-x-1/2 px-2 py-1 bg-slate-800 text-xs text-slate-300 rounded opacity-0 group-hover:opacity-100 transition-opacity">Minimize</span>
          </div>
          <div className="w-3 h-3 rounded-full bg-green-500 group cursor-pointer relative">
            <span className="absolute -top-8 left-1/2 -translate-x-1/2 px-2 py-1 bg-slate-800 text-xs text-slate-300 rounded opacity-0 group-hover:opacity-100 transition-opacity">Fullscreen</span>
          </div>
        </div>
        <div className="text-xs text-slate-400 flex items-center">
          {isLanguageAutoDetected && selectedLanguage && (
            <span className="px-1.5 py-0.5 bg-blue-500/20 text-blue-400 rounded text-xs">
              <span className="hidden sm:inline">Language </span>detected
            </span>
          )}
          <span className="mx-2 text-slate-600">●</span>
          code-editor.{selectedLanguage === 'javascript' ? 'js' : 
                      selectedLanguage === 'typescript' ? 'ts' : 
                      selectedLanguage === 'python' ? 'py' : 
                      selectedLanguage === 'java' ? 'java' : 
                      selectedLanguage === 'cpp' ? 'cpp' : 
                      selectedLanguage === 'html' ? 'html' : 
                      selectedLanguage === 'css' ? 'css' : 'txt'}
        </div>
        {/* Language selector */}
        <select
          value={selectedLanguage}
          onChange={handleLanguageChange}
          className="text-xs bg-slate-700 text-slate-300 border border-slate-600 rounded px-2 py-1 cursor-pointer focus:outline-none focus:ring-1 focus:ring-blue-500"
        >
          <option value="javascript">JavaScript</option>
          <option value="typescript">TypeScript</option>
          <option value="python">Python</option>
          <option value="java">Java</option>
          <option value="cpp">C++</option>
          <option value="html">HTML</option>
          <option value="css">CSS</option>
        </select>
      </div>
      <div className="relative flex">
        {/* Line numbers */}
        <div className="hidden sm:block py-3 px-2 text-right bg-slate-800/50 border-r border-slate-700/80 select-none">
          {lines.map(num => (
            <div key={num} className="text-xs text-slate-500 font-mono leading-5">{num}</div>
          ))}
          {/* Add an extra line for when user is at the end */}
          <div className="text-xs text-slate-500 font-mono leading-5">{lines.length + 1}</div>
        </div>

        {/* Code editor with syntax highlighting */}
        <div className="flex-1 relative group">
          <SyntaxHighlighter
            language={selectedLanguage}
            style={vscDarkPlus}
            customStyle={{
              background: 'transparent',
              padding: '1rem',
              margin: 0,
              minHeight: '350px',
              fontSize: '0.875rem',
              fontFamily: 'monospace',
              overflow: 'hidden',
            }}
          >
            {code || ' '}
          </SyntaxHighlighter>
          <textarea
            value={code}
            onChange={(e) => onChange(e.target.value)}
            onKeyDown={handleKeyDown}
            onPaste={handlePaste}
            onFocus={() => setIsFocused(true)}
            onBlur={() => setIsFocused(false)}
            placeholder={placeholder}
            className="absolute inset-0 bg-transparent text-transparent caret-slate-200 font-mono text-sm p-4 resize-none focus:outline-none min-h-[350px] w-full"
            spellCheck="false"
            autoComplete="off"
            autoCorrect="off"
            autoCapitalize="off"
          />
          
          {/* Placeholder when empty */}
          {!code && (
            <div className="absolute inset-0 pointer-events-none p-4 flex items-center justify-center">
              <div className="text-slate-500 text-sm flex items-center">
                <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5 mr-2 text-blue-400/50" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                  <path strokeLinecap="round" strokeLinejoin="round" d="M10 20l4-16m4 4l4 4-4 4M6 16l-4-4 4-4" />
                </svg>
                {placeholder}
              </div>
            </div>
          )}
        </div>
      </div>
      
      {/* Bottom toolbar */}
      <div className="flex items-center justify-between p-2 bg-slate-800/50 border-t border-slate-700/80 text-xs text-slate-500">
        <div className="flex items-center">
          <span className="px-2 border-r border-slate-700">{lines.length} lines</span>
          <span className="px-2">{code.length} chars</span>
        </div>
        <div className="flex items-center">
          <span className="px-2 border-r border-slate-700">{selectedLanguage}</span>
          <span className="px-2">UTF-8</span>
        </div>
      </div>
    </div>
  )
}

export default CodeEditor;