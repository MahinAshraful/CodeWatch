import React from 'react';
import LoadingIndicator from './LoadingIndicator';
import TerminalLogDisplay from './TerminalLogDisplay';

const LoadingScreen: React.FC = () => {
  // sample logs; adjust with your actual logs as needed
  const logs = ['Loading module 1...', 'Loading module 2...', 'Initializing...'];

  return (
    <div className="flex items-center justify-center h-screen">
      <div className="flex">
        <div className="mr-4">
          <LoadingIndicator />
        </div>
        <div>
          <TerminalLogDisplay logs={logs} />
        </div>
      </div>
    </div>
  );
};

export default LoadingScreen;