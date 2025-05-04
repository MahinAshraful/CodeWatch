import React from 'react';
import { Link } from 'react-router-dom';

const Navbar: React.FC = () => {
  return (
    <nav className="bg-gray-800 p-4">
      <div className="max-w-4xl mx-auto flex justify-between items-center">
        <Link to="/" className="text-white font-bold text-xl">
          CodeWatch
        </Link>
        <div className="space-x-4">
          <Link to="/" className="text-white hover:text-gray-300">
            Home
          </Link>
          <Link to="/how-it-works" className="text-white hover:text-gray-300">
            How It Works
          </Link>
          <Link to="/about" className="text-white hover:text-gray-300">
            About
          </Link>
        </div>
      </div>
    </nav>
  );
};

export default Navbar;
