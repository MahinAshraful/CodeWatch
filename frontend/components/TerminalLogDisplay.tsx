import React, { useRef, useEffect } from 'react';

interface TerminalLogDisplayProps {
  logs: string[];
}

const TerminalLogDisplay: React.FC<TerminalLogDisplayProps> = ({ logs }) => {
  const containerRef = useRef<HTMLDivElement>(null);

  useEffect(() => {
    if (containerRef.current) {
      containerRef.current.scrollTop = containerRef.current.scrollHeight;
    }
  }, [logs]);

  return (
    <div ref={containerRef} className="bg-black text-green-400 p-4 font-mono rounded overflow-y-auto h-64">
      <pre>
        {logs.join('\n')}
      </pre>
    </div>
  );
};

export default TerminalLogDisplay;