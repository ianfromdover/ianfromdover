'use client';
import { useState, useEffect } from "react";
import styles from 'app/components/dvd-box.module.css'
export default function DvdBox() {
  /**
   * Vibe coding convo: https://claude.ai/chat/8afb9fd0-5e8a-4c2e-9659-13e9e65ba004
   * Related docs from React: https://react.dev/learn/adding-interactivity
   * https://react.dev/learn/managing-state
   * State operates in 3 steps
   * 1. Trigger (when the set function is called)
   * 2. Render
   * 3. Commit to DOM (display)
   * 
   * one implementation: http://prgreen.github.io/blog/2013/09/30/the-bouncing-dvd-logo-explained/
   */
  const [position, setPosition] = useState({ x: 100, y: 100 });
  const [duration, setDuration] = useState(1);

  /**
   * Taken from MDN
   * @source https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Math/random
   * @param min Minimum float that you can get
   * @param max Same for max
   * @returns A random float x, where min <= x < max
   */
  function getRandomBtwn(min, max) {
    return Math.random() * (max - min) + min;
  }

  function changePosition() {
    const newX = Math.floor(Math.random() * 500);
    const newY = Math.floor(Math.random() * 500);
    const newDur = Math.random() * 1 + 0.3;

    setPosition({ x: newX, y: newY });
    setDuration(newDur);
  }

  // useEffect(() => {
  //   setTimeout(() => changePosition(), duration);
  // }, [duration]);

  return (
    <div className={styles.container}>
      <div
        className={styles.box}
        style={{
          left: `${position.x}px`,
          top: `${position.y}px`,
          transition: `${duration}s`,
        }}
      >
        Angry Box X_X
      </div>
      <button 
        className={styles.button} 
        onClick={changePosition}
      >
        Move to random location
      </button>
    </div>
  );
}

// to handle state of arrays and objects, you need to:
// create a new array(or copy one) and then set it as the new one

// array can use .map(currElem => currElem + 1) to return a new list 
// where + 1 is modification

// read more about handling state of arrays and objects
// https://react.dev/learn/adding-interactivity

