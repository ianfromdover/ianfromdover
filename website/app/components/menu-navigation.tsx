'use client';

import React, { useEffect, useRef } from 'react';
import useArrowKeyNavigation from '@/app/use-arrow-key-navigation';
import styles from './menu-navigation.module.css'; // Import CSS Module

const menuItems = ['work', 'about', 'contact', 'playground'];

function MenuNavigation() {
  const [focusedIndex] = useArrowKeyNavigation(menuItems.length);
  // store refs to the focusable buttons (not the <li>)
  const itemRefs = useRef<Array<HTMLButtonElement | null>>([]);

  const handleSelect = (item) => {
    console.log(`Navigating to: ${item}`);
  };

  useEffect(() => {
    const elem = itemRefs.current[focusedIndex];
    if (elem && typeof elem.focus === 'function') {
      elem.focus();
    }
  }, [focusedIndex]);

  return (
    <nav className={styles.menuNav} aria-label="Main Menu">
      <ul className={styles.menuList} role="menu">
        {menuItems.map((item, index) => {
          const isActive = index === focusedIndex;
          return (
            <li key={item} className={styles.menuItemWrapper} role="none">
              {/* rails (bottom-most visual) */}
              <div className={`${styles.rails} ${isActive ? styles.active : ''}`} aria-hidden="true" />
              {/* base (drop-shadow layer) */}
              <div className={`${styles.base} ${isActive ? styles.active : ''}`} aria-hidden="true" />
              {/* overlay (animates horizontally underneath text) */}
              <div className={`${styles.overlay} ${isActive ? styles.active : ''}`} aria-hidden="true" />
              {/* top-most interactive text + icon */}
              <button
                ref={(el) => (itemRefs.current[index] = el)}
                role="menuitem"
                tabIndex={-1} // programmatic focus via arrow keys
                className={`${styles.textIcon} ${isActive ? styles.active : ''}`}
                onClick={() => handleSelect(item)}
                onKeyDown={(e) => {
                  if (e.key === 'Enter' || e.key === ' ') {
                    e.preventDefault();
                    handleSelect(item);
                  }
                }}
              >
                {item.toUpperCase()}
              </button>
            </li>
          );
        })}
      </ul>
    </nav>
  );
}

export default MenuNavigation;
