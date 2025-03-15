'use client';
import { useState } from "react";
import styles from 'app/components/auto-layout.module.css';

export default function AutoLayout() {
  return (
    <div className={styles.autoLayout}>
      <p>I'm using this box to learn how to convert Figma Auto Layout into CSS</p>
      <p className={styles.innerBlock}>Cashback</p>
    </div>
  )
}
