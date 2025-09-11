import Link from 'next/link'
import styles from 'app/components/nav.module.css'

const navItems = {
  '/': {
    name: 'home',
  },
  '/blog': {
    name: 'blog',
  },
  '/playground': {
    name: 'playground',
  },
}

export function Navbar() {
  return (
    <aside>
      <div>
        <nav>
          <div className={styles.nav}>
            {Object.entries(navItems).map(([path, { name }]) => {
              return (
                <Link
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
