import Link from "next/link";

export default function NotFound() {
  return (
    <section>
      <h1>
        404 - Page Not Found
      </h1>
      <p>A faulty link has brought you to a page that does not exist.</p>
      <Link href="/">Return home</Link>
    </section>
  )
}

      // <h1 className="mb-8 text-2xl font-semibold tracking-tighter"></h1>
