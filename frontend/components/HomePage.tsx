import React from 'react';

const HomePage: React.FC = () => {
  return (
    <div className="max-w-4xl mx-auto p-6 bg-white rounded-lg shadow-md">
      <h1 className="text-3xl font-bold mb-4 text-gray-800">Welcome to CodeWatch</h1>
      <p className="text-gray-600">
        Your AI-powered code analysis platform for detecting and understanding code patterns.
      </p>
    </div>
  );
};

export default HomePage;
