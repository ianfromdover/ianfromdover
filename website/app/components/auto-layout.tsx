'use client';
import { useState, useEffect, useRef } from "react";
import styles from 'app/components/auto-layout.module.css';

export default function AutoLayout() {
  const audioRefHover = useRef<HTMLAudioElement | null>(null); // claude gave me this
  const audioRefClick = useRef<HTMLAudioElement | null>(null); // claude gave me this

  useEffect(() => {
    if (typeof window !== 'undefined') {
      //Only run in the browser.
      audioRefHover.current = new Audio('/azure-dreams/highlight.wav');
      audioRefClick.current = new Audio('/azure-dreams/click.wav');
    }
  }, []);

  const playSoundHover = () => playSound(audioRefHover.current);
  const playSoundClick = () => playSound(audioRefClick.current);

  const playSound = (currAudioRef) => {
    if (!currAudioRef) {
      return;
    }

    currAudioRef.currentTime = 0; // play the sound when hovering over others
    const playPromise = currAudioRef.play();
    // Silence the error, Safari users won't get audio on hover
    if (playPromise !== undefined) {
      playPromise.catch((error) => { });
    }
  };

  return (
    <div className={styles.parent}>
      <p>I'm using this box to learn how to convert Figma Auto Layout into CSS</p>
      <p className={styles.cashback}>Cashback</p>
      <div className={styles.box}>
        <button className={styles.a} onMouseEnter={playSoundHover} onClick={playSoundClick}></button>
        <button className={styles.b} onMouseEnter={playSoundHover} onClick={playSoundClick}></button>
        <button className={styles.c} onMouseEnter={playSoundHover} onClick={playSoundClick}></button>
      </div>
    </div>
  )
}
