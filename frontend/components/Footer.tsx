import React from 'react'

const Footer: React.FC = () => {
  return (
    <footer className="bg-slate-800 border-t border-slate-700 py-4">
      <div className="container mx-auto px-4">
        <div className="flex flex-col md:flex-row justify-between items-center">
          <div className="mb-4 md:mb-0">
            <p className="text-slate-400 text-sm">
              &copy; {new Date().getFullYear()} CodeDetect AI. All rights reserved.
            </p>
          </div>
          <div className="flex space-x-4">
            <a href="#" className="text-slate-400 hover:text-blue-400 transition-colors text-sm">
              Privacy Policy
            </a>
            <a href="#" className="text-slate-400 hover:text-blue-400 transition-colors text-sm">
              Terms of Service
            </a>
            <a href="#" className="text-slate-400 hover:text-blue-400 transition-colors text-sm">
              Contact
            </a>
          </div>
        </div>
      </div>
    </footer>
  )
}

export default Footer