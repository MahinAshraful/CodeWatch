import React, { useState, useEffect } from 'react';

const Header: React.FC = () => {
  const [isScrolled, setIsScrolled] = useState(false);
  const [mobileMenuOpen, setMobileMenuOpen] = useState(false);
  const [glowPosition, setGlowPosition] = useState({ x: 0, y: 0 });
  
  useEffect(() => {
    const handleScroll = () => {
      setIsScrolled(window.scrollY > 10);
    };
    window.addEventListener('scroll', handleScroll);
    return () => window.removeEventListener('scroll', handleScroll);
  }, []);
  
  const handleMouseMove = (e) => {
    const rect = e.currentTarget.getBoundingClientRect();
    setGlowPosition({
      x: e.clientX - rect.left,
      y: e.clientY - rect.top
    });
  };
  
  return (
    <header 
      className={`sticky top-0 z-50 transition-all duration-300 ${
        isScrolled 
          ? 'bg-slate-900/90 backdrop-blur-md shadow-lg border-b border-blue-500/20' 
          : 'bg-slate-800/80 border-b border-slate-700/50'
      }`}
    >
      <div className="container mx-auto px-4 py-3">
        <div className="flex justify-between items-center">
          <a 
            href="/" 
            className="group flex items-center space-x-3 relative overflow-hidden rounded-full px-3 py-2"
            onMouseMove={handleMouseMove}
          >
            <div 
              className="absolute rounded-full bg-blue-500/20 w-12 h-12 blur-xl opacity-0 group-hover:opacity-100 transition-opacity duration-500"
              style={{ 
                left: `${glowPosition.x - 24}px`, 
                top: `${glowPosition.y - 24}px` 
              }}
            />
            
            <div className="bg-transparent w-9 h-8 rounded-full flex items-center justify-center relative z-10 group-hover:scale-110 transition-transform duration-300">
              <img src="./logo.png" alt="CodeWatch Logo" className="relative z-10" />
              <div className="absolute inset-0 bg-blue-500/10 rounded-full opacity-0 group-hover:opacity-100 transition-opacity duration-300" />
            </div>
            
            <div className="relative z-10">
              <h1 className="text-2xl font-bold bg-gradient-to-r from-blue-400 via-indigo-400 to-purple-500 bg-clip-text text-transparent relative z-10">
                CodeWatch
              </h1>
              <div className="h-0.5 w-0 bg-gradient-to-r from-blue-500 to-purple-500 group-hover:w-full transition-all duration-300" />
            </div>
          </a>
          
          <nav className="hidden md:block">
            <ul className="flex items-center space-x-10">
              <li>
                <a 
                  href="/how-it-works" 
                  className="text-blue-400 hover:text-blue-300 transition-colors text-lg font-bold px-3 py-2 relative group"
                >
                  <span>How It Works</span>
                  <span className="absolute bottom-0 left-0 w-full h-0.5 bg-blue-500/50 scale-x-0 group-hover:scale-x-100 transition-transform origin-left duration-300"></span>
                </a>
              </li>
              <li>
                <a 
                  href="/about" 
                  className="text-blue-400 hover:text-blue-300 transition-colors text-lg font-bold px-3 py-2 relative group"
                >
                  <span>About</span>
                  <span className="absolute bottom-0 left-0 w-full h-0.5 bg-blue-500/50 scale-x-0 group-hover:scale-x-100 transition-transform origin-left duration-300"></span>
                </a>
              </li>
              <li>
                <a 
                  href="https://github.com/MahinAshraful/CodeWatch" 
                  target="_blank" 
                  rel="noopener noreferrer" 
                  className="flex items-center space-x-1 text-slate-200 bg-slate-700/80 hover:bg-slate-600 transition-colors rounded-lg px-4 py-2 text-base font-medium shadow-md"
                >
                  <span>GitHub</span>
                  <svg className="w-3 h-3" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                    <path strokeLinecap="round" strokeLinejoin="round" d="M10 6H6a2 2 0 00-2 2v10a2 2 0 002 2h10a2 2 0 002-2v-4M14 4h6m0 0v6m0-6L10 14" />
                  </svg>
                </a>
              </li>
            </ul>
          </nav>
          
          <button 
            className="md:hidden p-2 text-slate-300 hover:text-white focus:outline-none"
            onClick={() => setMobileMenuOpen(!mobileMenuOpen)}
          >
            {mobileMenuOpen ? 
              <svg className="w-6 h-6" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                <path strokeLinecap="round" strokeLinejoin="round" d="M6 18L18 6M6 6l12 12" />
              </svg> : 
              <svg className="w-6 h-6" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                <path strokeLinecap="round" strokeLinejoin="round" d="M4 6h16M4 12h16M4 18h16" />
              </svg>
            }
          </button>
        </div>
        
        {mobileMenuOpen && (
          <div className="md:hidden mt-4 pt-4 border-t border-slate-700/50">
            <nav>
              <ul className="space-y-4">
                <li>
                  <a 
                    href="/how-it-works" 
                    className="text-blue-400 hover:text-blue-300 transition-colors text-lg font-bold block py-2"
                    onClick={() => setMobileMenuOpen(false)}
                  >
                    How It Works
                  </a>
                </li>
                <li>
                  <a 
                    href="/about" 
                    className="text-blue-400 hover:text-blue-300 transition-colors text-lg font-bold block py-2"
                    onClick={() => setMobileMenuOpen(false)}
                  >
                    About
                  </a>
                </li>
                <li>
                  <a 
                    href="https://github.com/MahinAshraful/CodeWatch" 
                    target="_blank" 
                    rel="noopener noreferrer" 
                    className="flex items-center space-x-1 text-slate-200 bg-slate-700/80 hover:bg-slate-600 transition-colors rounded-lg px-4 py-2 text-base font-medium shadow-md w-full"
                  >
                    <span>GitHub</span>
                    <svg className="w-3 h-3" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                      <path strokeLinecap="round" strokeLinejoin="round" d="M10 6H6a2 2 0 00-2 2v10a2 2 0 002 2h10a2 2 0 002-2v-4M14 4h6m0 0v6m0-6L10 14" />
                    </svg>
                  </a>
                </li>
              </ul>
            </nav>
          </div>
        )}
      </div>
    </header>
  );
};

export default Header;