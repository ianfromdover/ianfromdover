"use client"
import Link from 'next/link'
import React, { useState } from 'react';
import styles from 'app/components/nav.module.css'

const navItems = {
  '/': {
    name: 'home',
    id: 'h',
  },
  '/blog': {
    name: 'blog',
    id: 'b',
  },
  '/about': {
    name: 'about',
    id: 'a',
  },
  '/playground': {
    name: 'playground',
    id: 'p',
  },
}

export function Navbar() {
  const [activePage, setActivePage] = useState('h');

  const handleClick = (page) => {
    setActivePage(page);
  };

  return (
    <aside>
      <div>
        <nav>
          <div className={styles.nav}>
            {Object.entries(navItems).map(([path, { name, id }]) => {
              return (
                <Link
                  onClick={() => handleClick(id)}
                  className={`${styles.btn} ${activePage === id ? styles.btnSelected : ''}`}
                  key={path}
                  href={path}
                >
                  {name}
                </Link>
              )
            })}
          </div>
        </nav>
      </div>
    </aside>
  )
}
