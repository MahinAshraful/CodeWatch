import React, { useState, useEffect } from 'react';
import { Link } from 'react-router-dom';

const Header: React.FC = () => {
  const [scrolled, setScrolled] = useState(false);
  
  useEffect(() => {
    const handleScroll = () => {
      setScrolled(window.scrollY > 20);
    };
    window.addEventListener('scroll', handleScroll);
    return () => window.removeEventListener('scroll', handleScroll);
  }, []);

  return (
    <header className={`sticky top-0 z-50 transition-all duration-300 ${
      scrolled ? 'bg-slate-900/90 backdrop-blur-md shadow-md' : 'bg-transparent'
    }`}>
      <div className="container mx-auto px-4 py-4">
        <div className="flex justify-between items-center">
          <div className="flex items-center space-x-2">
            <div className=" w-10 h-10 rounded-md flex items-center justify-center shadow-lg relative overflow-hidden group">
              {/* Logo image */}
              <img 
                src="/images/logo.png" 
                alt="CodeWatch Logo" 
                className="h-10 w-10 object-contain z-10 group-hover:scale-110 transition-transform duration-300"
              />
              <div className="absolute inset-0 bg-gradient-to-tr from-blue-200 to-blue-100 opacity-0 group-hover:opacity-100 transition-opacity duration-300"></div>
            </div>
            <Link to="/" className="group">
              <h1 className="text-xl font-bold">
                <span className="bg-clip-text text-transparent bg-gradient-to-r from-blue-400 to-indigo-500 relative">
                  CodeWatch
                  <span className="absolute -bottom-1 left-0 w-full h-0.5 bg-gradient-to-r from-blue-500 to-indigo-500/10 scale-x-0 group-hover:scale-x-100 transition-transform origin-left duration-300"></span>
                </span>
              </h1>
            </Link>
          </div>
          
          <nav>
            <ul className="flex space-x-6">
              <li>
                <Link to="/how-it-works" className="text-blue-400 hover:text-blue-300 transition-colors flex items-center space-x-1 border-b border-transparent hover:border-blue-500 py-1">
                  <span>How It Works</span>
                </Link>
              </li>
              <li>
                <Link to="/about" className="text-blue-400 hover:text-blue-300 transition-colors flex items-center space-x-1 border-b border-transparent hover:border-blue-500 py-1">
                  <span>About</span>
                </Link>
              </li>
              <li>
                <a 
                  href="https://github.com/MahinAshraful/CodeWatch" 
                  target="_blank" 
                  rel="noopener noreferrer" 
                  className="text-blue-400 hover:text-white transition-colors py-1.5 px-4 rounded-md border border-blue-500/50 hover:bg-blue-600 hover:border-blue-600 transition-all"
                >
                  GitHub
                </a>
              </li>
            </ul>
          </nav>
        </div>
      </div>
    </header>
  );
};

export default Header;