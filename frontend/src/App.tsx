// import './App.css'
// import Layout from '../components/Layout.tsx'
// import CodeDetectionPage from '../components/CodeDetectionPage'

// function App() {
//   return (
//     <Layout>
//       <CodeDetectionPage />
//     </Layout>
//   )
// }

// export default App

import React from 'react';
import { BrowserRouter, Routes, Route } from 'react-router-dom';
import Layout from '../components/Layout.tsx';
import CodeDetectionPage from '../components/CodeDetectionPage';
import HowItWorksPage from '../components/HowItWorksPage';
import AboutPage from '../components/AboutPage';

const App: React.FC = () => {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={
          <Layout>
            <CodeDetectionPage />
          </Layout>
        } />
        <Route path="/how-it-works" element={
          <Layout>
            <HowItWorksPage />
          </Layout>
        } />
        <Route path="/about" element={
          <Layout>
            <AboutPage />
          </Layout>
        } />
      </Routes>
    </BrowserRouter>
  );
};

export default App;