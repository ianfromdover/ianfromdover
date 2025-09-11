import LikeButton from 'app/components/like-button' // client component for interactivity
import AutoLayout from 'app/components/auto-layout'
import DvdBox from 'app/components/dvd-box'

export const metadata = {
  title: 'Playground',
  description: 'Somewhere to experiment with React until it looks better.',
}

// <!-- h1 className="font-semibold text-2xl mb-8 tracking-tighter" -->
export default function Page() {
  const fav_foods = ['Cup noodles', 'Meiji milk', 'Hot chocolate'];

  return (
    <section>
      <h1>Playground</h1>
      <h3>
        My favourite foods are:
      </h3>
      <ol>
        {fav_foods.map(food => (
          <div key={food}>
            <li key={food}>{food}</li>
            <LikeButton key={food + "l"}/>
          </div>
        ))}
      </ol>
      <p>
        If you like any of them, Like them too!
      </p>
      <AutoLayout />
      <DvdBox />
    </section>
  )
}
