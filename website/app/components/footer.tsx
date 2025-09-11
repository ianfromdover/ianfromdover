import styles from 'app/components/footer.module.css';
function ArrowIcon() {
  return (
    <svg
      width="12"
      height="12"
      viewBox="0 0 12 12"
      fill="none"
      xmlns="http://www.w3.org/2000/svg"
    >
      <path
        d="M2.07102 11.3494L0.963068 10.2415L9.2017 1.98864H2.83807L2.85227 0.454545H11.8438V9.46023H10.2955L10.3097 3.09659L2.07102 11.3494Z"
        fill="currentColor"
      />
    </svg>
  )
}

export default function Footer() {
  return (
    <footer className={styles.h}>
      <ul className={styles.list}>
        <li>
          <a
            className={styles.anchorChild}
            rel="noopener noreferrer"
            target="_blank"
            href="https://www.linkedin.com/in/hongyienian/"
          >
            <ArrowIcon />
            <p>my linkedin</p>
          </a>
        </li>
        <li>
          <a
            className={styles.anchorChild}
            rel="noopener noreferrer"
            target="_blank"
            href="https://github.com/ianfromdover/ianfromdover/tree/main/website"
          >
            <ArrowIcon />
            <p>github</p>
          </a>
        </li>
        <li>
          <a
            className={styles.anchorChild}
            rel="noopener noreferrer"
            target="_blank"
            href="https://vercel.com/templates/next.js/portfolio-starter-kit"
          >
            <ArrowIcon />
            <p>template</p>
          </a>
        </li>
      </ul>
      <p>
        © IAN HONG ♦ OCT 2025
      </p>
    </footer>
  )
}
