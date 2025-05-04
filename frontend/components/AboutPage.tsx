import React from 'react';

const AboutPage = () => {
  const teamMembers = [
    {
      name: "Ashraful Mahin",
      role: "Hunter College May 27'",
      linkedIn: "http://linkedin.com/in/ashraful-mahin/"
    },
    {
      name: "Nakib Abedin",
      role: "Hunter College May 26'",
      linkedIn: "https://www.linkedin.com/in/nakibabedin/"
    },
    {
      name: "Zhen Tao Pan",
      role: "Hunter College May 27'",
      linkedIn: "https://www.linkedin.com/in/zhen-tao-pan-4045a52a0/"
    },
    {
      name: "Ataur Muhith",
      role: "Hunter College Dec 25'",
      linkedIn: "https://www.linkedin.com/in/ataurmuhith/"
    }
  ];
  
  return (
    <div className="bg-slate-800/60 rounded-xl shadow-xl overflow-hidden border border-slate-700/50 backdrop-blur-sm p-6">
      <div className="max-w-3xl mx-auto">
        {/* Hero Section with animation */}
        <div className="flex items-center justify-center mb-8">
          <div className="bg-blue-600 w-16 h-16 rounded-xl shadow-lg flex items-center justify-center mr-5 relative overflow-hidden group">
            <svg xmlns="http://www.w3.org/2000/svg" className="h-9 w-9 text-white z-10 group-hover:scale-110 transition-transform duration-300" viewBox="0 0 24 24" fill="none" stroke="currentColor" strokeWidth="2">
              <path strokeLinecap="round" strokeLinejoin="round" d="M10 20l4-16m4 4l4 4-4 4M6 16l-4-4 4-4" />
            </svg>
            <div className="absolute inset-0 bg-gradient-to-tr from-blue-700 to-blue-500 opacity-0 group-hover:opacity-100 transition-opacity duration-300"></div>
            <div className="absolute -inset-full h-full w-1/2 z-5 block transform -skew-x-12 bg-gradient-to-r from-transparent to-white opacity-40 group-hover:animate-shine" />
          </div>
          <h1 className="text-4xl font-bold bg-clip-text text-transparent bg-gradient-to-r from-blue-400 via-blue-500 to-indigo-600">
            We Are CodeWatch
          </h1>
        </div>
      
        {/* Main content */}
        <div className="space-y-8 text-slate-300">
          <p className="text-xl leading-relaxed text-center">
            A team of developers, researchers, and AI enthusiasts pushing the boundaries 
            of what's possible at the intersection of code and artificial intelligence.
          </p>
          
          {/* Team section */}
          <div className="mt-10">
            <div className="grid grid-cols-1 sm:grid-cols-2 gap-6">
              {teamMembers.map((member, index) => (
                <div 
                  key={index}
                  className="bg-gradient-to-br from-slate-900/80 to-slate-800/80 rounded-xl p-5 border border-slate-700/60 hover:border-blue-500/30 transition-all duration-300 hover:shadow-lg hover:shadow-blue-500/10 hover:translate-y-[-4px] group"
                >
                  <h3 className="text-lg font-semibold text-white mb-1 group-hover:text-blue-400 transition-colors duration-300">{member.name}</h3>
                  <p className="text-blue-400 text-sm mb-3">{member.role}</p>
                  <a 
                    href={member.linkedIn} 
                    target="_blank" 
                    rel="noopener noreferrer"
                    className="inline-flex items-center text-sm text-slate-400 hover:text-blue-400 transition-colors duration-300"
                  >
                    <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" className="mr-1" viewBox="0 0 16 16">
                      <path d="M0 1.146C0 .513.526 0 1.175 0h13.65C15.474 0 16 .513 16 1.146v13.708c0 .633-.526 1.146-1.175 1.146H1.175C.526 16 0 15.487 0 14.854V1.146zm4.943 12.248V6.169H2.542v7.225h2.401zm-1.2-8.212c.837 0 1.358-.554 1.358-1.248-.015-.709-.52-1.248-1.342-1.248-.822 0-1.359.54-1.359 1.248 0 .694.521 1.248 1.327 1.248h.016zm4.908 8.212V9.359c0-.216.016-.432.08-.586.173-.431.568-.878 1.232-.878.869 0 1.216.662 1.216 1.634v3.865h2.401V9.25c0-2.22-1.184-3.252-2.764-3.252-1.274 0-1.845.7-2.165 1.193v.025h-.016a5.54 5.54 0 0 1 .016-.025V6.169h-2.4c.03.678 0 7.225 0 7.225h2.4z"/>
                    </svg>
                    Connect
                  </a>
                </div>
              ))}
            </div>
          </div>
          
          {/* Our Vision Section */}
          <div className="mt-10 bg-gradient-to-r from-blue-600/10 to-indigo-600/10 border border-blue-500/20 rounded-xl p-6 shadow-inner">
            <h2 className="text-2xl font-bold text-white mb-4">Our Vision</h2>
            <p className="text-slate-300 leading-relaxed">
              We're building tools that change the use of AI forever, whether in the classroom or during an interview we are building
              the next generation of tools from groundbreaking research
            </p>
          </div>
          
          {/* Footer */}
          <div className="mt-10 pt-6 border-t border-slate-700/30 text-center text-sm text-slate-500">
            <p>© {new Date().getFullYear()} CodeWatch. All rights reserved.</p>
          </div>
        </div>
      </div>
    </div>
  );
};

export default AboutPage;