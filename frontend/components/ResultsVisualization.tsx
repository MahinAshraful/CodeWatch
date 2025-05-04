import React, { useEffect, useState } from 'react';
import { 
  BarChart, Bar, XAxis, YAxis, Tooltip, ResponsiveContainer, TooltipProps,
  RadarChart, PolarGrid, PolarAngleAxis, Radar, 
  PieChart, Pie, Cell, Legend
} from 'recharts';

interface ResultsProps {
  original_similarity: number;
  ai_similarity: number;
  difference: number;
  result: string;
}

interface CustomTooltipProps {
  active?: boolean;
  payload?: Array<{
    value: number;
    name: string;
    dataKey: string;
    color?: string;
  }>;
  label?: string;
}

const ResultsVisualization: React.FC<{ results: ResultsProps }> = ({ results }) => {
  const [animate, setAnimate] = useState(false);
  
  useEffect(() => {
    setAnimate(true);
  }, []);
  
  const barData = [
    {
      name: 'Original Code',
      value: results.original_similarity,
      fill: '#3b82f6', // blue
    },
    {
      name: 'AI-Generated',
      value: results.ai_similarity,
      fill: '#f59e0b', // amber
    }
  ];
  
  const radarData = [
    {
      subject: 'Original Similarity',
      A: results.original_similarity,
      fullMark: 1,
    },
    {
      subject: 'AI Similarity',
      A: results.ai_similarity,
      fullMark: 1,
    },
    {
      subject: 'Difference',
      A: Math.min(results.difference * 10, 1), 
      fullMark: 1,
    },
  ];
  
  const getVerdictData = () => {
    let aiProbability = 0;
    
    if (results.result.includes('VERY LIKELY AI-GENERATED')) {
      aiProbability = 0.95;
    } else if (results.result.includes('LIKELY AI-GENERATED')) {
      aiProbability = 0.75;
    } else if (results.result.includes('POSSIBLY AI-GENERATED')) {
      aiProbability = 0.5;
    } else {
      aiProbability = 0.2;
    }
    
    return [
      { name: 'AI-Generated', value: aiProbability },
      { name: 'Human-Written', value: 1 - aiProbability }
    ];
  };
  
  const pieData = getVerdictData();
  const COLORS = ['#3b82f6', '#10b981']; 
  
  const CustomTooltip: React.FC<CustomTooltipProps> = ({ active, payload, label }) => {
    if (active && payload && payload.length) {
      return (
        <div className="bg-slate-800 p-2 rounded border border-slate-700 text-white text-xs">
          <p>{`${label || payload[0].name}: ${(payload[0].value).toFixed(4)}`}</p>
        </div>
      );
    }
    return null;
  };
  
  return (
    <div className={`mt-8 transition-all duration-700 ${animate ? 'opacity-100' : 'opacity-0'}`}>
      <h3 className="text-xl text-white font-semibold mb-6 flex items-center">
        <svg xmlns="http://www.w3.org/2000/svg" className="h-5 w-5 mr-2 text-blue-400" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
          <path strokeLinecap="round" strokeLinejoin="round" d="M9 19v-6a2 2 0 00-2-2H5a2 2 0 00-2 2v6a2 2 0 002 2h2a2 2 0 002-2zm0 0V9a2 2 0 012-2h2a2 2 0 012 2v10m-6 0a2 2 0 002 2h2a2 2 0 002-2m0 0V5a2 2 0 012-2h2a2 2 0 012 2v14a2 2 0 01-2 2h-2a2 2 0 01-2-2z" />
        </svg>
        Visual Analysis
      </h3>
      
      <div className="grid grid-cols-1 md:grid-cols-2 gap-6">
        <div className="bg-slate-800/60 rounded-lg p-5 border border-slate-700/50">
          <h4 className="text-slate-300 font-medium mb-4 text-center">Similarity Comparison</h4>
          <div className="h-64">
            <ResponsiveContainer width="100%" height="100%">
              <BarChart
                data={barData}
                margin={{ top: 10, right: 10, left: 0, bottom: 10 }}
              >
                <XAxis dataKey="name" tick={{ fill: '#94a3b8' }} />
                <YAxis domain={[0, 1]} tick={{ fill: '#94a3b8' }} />
                <Tooltip content={<CustomTooltip />} />
                <Bar dataKey="value" />
              </BarChart>
            </ResponsiveContainer>
          </div>
          <p className="text-xs text-slate-400 mt-2 text-center">
            Higher similarity in AI-generated samples indicates automated creation
          </p>
        </div>
        
        <div className="bg-slate-800/60 rounded-lg p-5 border border-slate-700/50">
          <h4 className="text-slate-300 font-medium mb-4 text-center">Verdict Assessment</h4>
          <div className="h-64">
            <ResponsiveContainer width="100%" height="100%">
              <PieChart>
                <Pie
                  data={pieData}
                  cx="50%"
                  cy="50%"
                  innerRadius={60}
                  outerRadius={80}
                  paddingAngle={5}
                  dataKey="value"
                  label={({ name, percent }) => `${name}: ${(percent * 100).toFixed(0)}%`}
                >
                  {pieData.map((entry, index) => (
                    <Cell key={`cell-${index}`} fill={COLORS[index % COLORS.length]} />
                  ))}
                </Pie>
                <Tooltip content={<CustomTooltip />} />
                <Legend />
              </PieChart>
            </ResponsiveContainer>
          </div>
          <p className="text-xs text-slate-400 mt-2 text-center">
            Probability assessment based on pattern analysis
          </p>
        </div>
        
        <div className="bg-slate-800/60 rounded-lg p-5 border border-slate-700/50 md:col-span-2">
          <h4 className="text-slate-300 font-medium mb-4 text-center">Pattern Analysis</h4>
          <div className="h-72">
            <ResponsiveContainer width="100%" height="100%">
              <RadarChart outerRadius={90} data={radarData}>
                <PolarGrid stroke="#475569" />
                <PolarAngleAxis dataKey="subject" tick={{ fill: '#94a3b8' }} />
                <Radar
                  name="Code Patterns"
                  dataKey="A"
                  stroke="#3b82f6"
                  fill="#3b82f6"
                  fillOpacity={0.5}
                />
                <Tooltip content={<CustomTooltip />} />
              </RadarChart>
            </ResponsiveContainer>
          </div>
          <p className="text-xs text-slate-400 mt-2 text-center">
            Radar visualization shows the relationship between different similarity metrics
          </p>
        </div>
      </div>
    </div>
  );
};

export default ResultsVisualization;