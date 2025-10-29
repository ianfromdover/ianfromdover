'use client';
import { useState } from "react";
import styles from 'app/components/typing-text.module.css'

export default function TypingText({ children }) {
  const [animate, setAnimate] = useState(true);

  const handleRestart = () => {
    setAnimate(false);
    setTimeout(() => setAnimate(true), 10); // Small delay to re-add class
  };

  const widthBasedOnCharCount = `${children.length}ch`;

  return (
    <>
      <h1 
        className={animate ? styles.typingText : ''} 
        style={{ width: widthBasedOnCharCount }} 
        onClick={handleRestart}
      >
        {children}
      </h1>
    </>
  )
}
