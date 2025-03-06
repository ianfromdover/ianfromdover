import { BlogPosts } from 'app/components/posts'

export const metadata = {
  title: 'Blog',
  description: 'Read my thoughts.',
}

// <!-- h1 className="font-semibold text-2xl mb-8 tracking-tighter" -->
export default function Page() {
  return (
    <section>
      <h1>My Blog</h1>
      <BlogPosts />
    </section>
  )
}
