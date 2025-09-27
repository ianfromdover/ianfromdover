'use client';
import { useState } from "react";
import styles from 'app/components/typing-text.module.css'

export default function TypingText() {
  const [animate, setAnimate] = useState(true);

  const handleRestart = () => {
    setAnimate(false);
    setTimeout(() => setAnimate(true), 10); // Small delay to re-add class
  };

  return (
    <>
      <p className={animate ? styles.typingText : ''}>
        Thanks for reading my prose, but I think code completion kinda fogs up my brain a little.
      </p>
      <button onClick={handleRestart}>Restart Animation</button>
    </>
  )
}
