import React from 'react'

const Header: React.FC = () => {
  return (
    <header className="bg-slate-800 border-b border-slate-700">
      <div className="container mx-auto px-4 py-4 flex justify-between items-center">
        <div className="flex items-center space-x-2">
          <div className="bg-blue-500 w-8 h-8 rounded-md flex items-center justify-center">
            <img src="../public/logo.png" alt="" />
          </div>
          <h1 className="text-xl font-bold bg-gradient-to-r from-blue-400 to-purple-500 bg-clip-text text-transparent">CodeWatch</h1>
        </div>
        <nav>
          <ul className="flex space-x-6">
            <li><a href="/how-it-works" className="text-blue-400 hover:text-blue-300 transition-colors">How It Works</a></li>
            <li><a href="/about" className="text-blue-400 hover:text-blue-300 transition-colors">About</a></li>
            <li><a href="https://github.com/MahinAshraful/CodeWatch" target="_blank" rel="noopener noreferrer" className="text-blue-400 hover:text-blue-300 transition-colors">GitHub</a></li>
          </ul>
        </nav>
      </div>
    </header>
  )
}

export default Header