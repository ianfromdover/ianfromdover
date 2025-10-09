'use client';

import React, { useEffect, useRef } from 'react';
import useArrowKeyNavigation from '@/app/use-arrow-key-navigation';
import styles from './menu-navigation.module.css'; // Import CSS Module

const menuItems = ['work', 'about', 'contact', 'playground'];

function MenuNavigation() {
  const [focusedIndex] = useArrowKeyNavigation(menuItems.length);
  const itemRefs = useRef<Array<HTMLLIElement | null>>([]);

  const handleSelect = (item) => {
    console.log(`Navigating to: ${item}`);
  };

  useEffect(() => {
    const elem = itemRefs.current[focusedIndex];
    if (elem && typeof elem.focus === 'function') {
      elem.focus();
    }
  }, [focusedIndex]);

  /**
   * to fix: 
   * - enter and spacebar doesn't trigger click when using arrow key navigation
   * - tab doesn't work to focus on the menu items, menu items are not actually focusable
   */
  /**
   * One item is a div, which should compose of, in z-index order (top to bottom):
   * 4. text and icon (fades colour when active)
   * 3. overlay (scales horizontally when active)
   * 2. base (adds drop shadow when active)
   * 1. rails (fades in and scales vertically when active)
   */
  return (
    <nav className={styles.menuNav} aria-label="Main Menu">
      <ul className={styles.menuList} role="menu">
        {menuItems.map((item, index) => (
          <div key={item} className={styles.menuItemWrapper} style={{ position: 'relative' }}>
            <li
              role="menuitem"
              className={`${styles.menuItem} ${index === focusedIndex ? styles.active : ''}`}
              onClick={() => handleSelect(item)}
              onKeyDown={(e) => {
                if (e.key === 'Enter') {
                  handleSelect(item);
                }
              }}
              ref={el => itemRefs.current[index] = el}
            >
              {item.toUpperCase()}
            </li>
            <div className={styles.rails}>
              {item.toUpperCase()}
            </div>
          </div>
        ))}
      </ul>
    </nav>
  );
}

export default MenuNavigation;
