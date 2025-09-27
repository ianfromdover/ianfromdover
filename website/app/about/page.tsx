export const metadata = {
  title: 'About',
  description: 'About me!',
}

// <!-- h1 className="font-semibold text-2xl mb-8 tracking-tighter" -->
export default function Page() {
  const fav_foods = ['Cup noodles', 'Meiji milk', 'Hot chocolate'];

  return (
    <section>
      <h1>Hi, I'm Ian!</h1>
      <p>
        (A concise value proposition to recruiters) I'm a UX designer with a computer science background based in Singapore. I specialise in rigorous user research and designing user-centered solutions that are technically feasible.
      </p>
      <p>
        In my spare time, I love reading the bible, enjoying conversations with friends, and learning songs by ear. Looking forward to meeting you 😃
      </p>
    </section>
  )
}
