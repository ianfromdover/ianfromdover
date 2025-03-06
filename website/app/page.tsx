// Main page of the application
import { BlogPosts } from 'app/components/posts'
import LikeButton from 'app/components/likeButton' // client component for interactivity
// by default, in next.js, all components are server components and are stateless

/*
      <h1 className="mb-8 text-2xl font-semibold tracking-tighter">
      <p className="mb-4">
      <div className="my-8">
*/
export default function Page() { // the export default says this is the main component to render for the page
  const fav_foods = ['Cup noodles', 'Meiji milk', 'Hot chocolate'];

  return (
    <section>
      <Header title="I love Vim a LOT!!"/>
      <h1>
        My Portfolio
      </h1>
      <p>
        {`I'm a Vim enthusiast and tab advocate, finding unmatched efficiency in
        Vim's keystroke commands and tabs' flexibility for personal viewing
        preferences. This extends to my support for static typing, where its
        early error detection ensures cleaner code, and my preference for dark
        mode, which eases long coding sessions by reducing eye strain.`}
      </p>
      <h3>
        My favourite foods are:
      </h3>
      <ol>
        {fav_foods.map(food => (
          <div>
            <li key={food}>{food}</li>
            <LikeButton key={food + "l"}/>
          </div>
        ))}
      </ol>
      <p>
        If you like any of them, Like them too!
      </p>
      <div>
        <BlogPosts />
      </div>
    </section>
  )
}

function Header({ title }) { // props is an object with a property "title".
  // props is { title: "I love Vim a LOT!!" } javascript object
  // instead of 'props', use named destructuring in the params to get the value
  return (
    <h1>
      {title}
    </h1>
  )
}
