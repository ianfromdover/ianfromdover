import LikeButton from 'app/components/like-button' // client component for interactivity
import AutoLayout from 'app/components/auto-layout'
import DvdBox from 'app/components/dvd-box'
import TypingText from 'app/components/typing-text'
import MenuNavigation from '../components/menu-navigation'
import Image from 'next/image'

export const metadata = {
  title: 'Playground',
  description: 'Somewhere to experiment with React until it looks better.',
}

// <!-- h1 className="font-semibold text-2xl mb-8 tracking-tighter" -->
export default function Page() {
  const fav_foods = ['Cup noodles', 'Meiji milk', 'Hot chocolate'];

  return (
    <div>
      <section>
        <h1>Playground</h1>
        <p>A page where I can experiment with React components and animations.</p>
        <p>Things that will be added are:</p>
        <ul>
          <li>Typing text effect √</li>
          <li>Picture that is rendered using dither characters</li>
          <li>up-down arrow movement for selecting things in menus</li>
          <li>scaffold for OS game</li>
        </ul>
        <h3>
          Menu with up-down arrow key navigation
        </h3>
        <MenuNavigation />
        <h3>
          Typing text effect
        </h3>
        <TypingText>I'm testing this typing thing again that i'm going to use on the landing page. But i'm not sure how to decide p or h1 from the usage part</TypingText>
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
      <section>
        <h3>Previous website versions</h3>

        <Image
          src='/img/2.png'
          width={1920/4}
          height={1080/4}
          alt="How the website looks like in Sep 2025"
        />
        <p>Sep 2025</p>
        <br />

        <Image
          src='/img/1.png'
          width={1920/4}
          height={1080/4}
          alt="How the website looks like in Apr 2025"
        />
        <p>Apr 2025</p>
      </section>
    </div>
  )
}
