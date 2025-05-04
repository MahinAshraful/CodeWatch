import React from 'react';

const Footer: React.FC = () => {
  return (
    <footer className="bg-slate-900 border-t border-slate-800">
      <div className="container mx-auto px-4 py-8">
        <div className="flex flex-col md:flex-row justify-between items-center">
          <div className="mb-4 md:mb-0 flex items-center">
            <div className="bg-blue-700/20 p-1.5 rounded mr-3">
              <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5 text-blue-400" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
                <path strokeLinecap="round" strokeLinejoin="round" d="M10 20l4-16m4 4l4 4-4 4M6 16l-4-4 4-4" />
              </svg>
            </div>
            <p className="text-slate-400 text-sm">
              &copy; {new Date().getFullYear()} CodeWatch AI. All rights reserved.
            </p>
          </div>
          <div className="flex space-x-6">
            <a href="#" className="text-slate-400 hover:text-blue-400 transition-colors text-sm relative group">
              <span>Privacy Policy</span>
              <span className="absolute -bottom-1 left-0 w-full h-0.5 bg-blue-500/50 scale-x-0 group-hover:scale-x-100 transition-transform origin-left duration-300"></span>
            </a>
            <a href="#" className="text-slate-400 hover:text-blue-400 transition-colors text-sm relative group">
              <span>Terms of Service</span>
              <span className="absolute -bottom-1 left-0 w-full h-0.5 bg-blue-500/50 scale-x-0 group-hover:scale-x-100 transition-transform origin-left duration-300"></span>
            </a>
            <a href="#" className="text-slate-400 hover:text-blue-400 transition-colors text-sm relative group">
              <span>Contact</span>
              <span className="absolute -bottom-1 left-0 w-full h-0.5 bg-blue-500/50 scale-x-0 group-hover:scale-x-100 transition-transform origin-left duration-300"></span>
            </a>
          </div>
        </div>
      </div>
    </footer>
  );
};

export default Footer;