// Main page of the application
// by default, in next.js, all components are server components and are stateless

import TypingText from "./components/typing-text"

/*
      <h1 className="mb-8 text-2xl font-semibold tracking-tighter">
      <p className="mb-4">
      <div className="my-8">
*/
export default function Page() { // the export default says this is the main component to render for the page

  return (
    <div>
      <section>
        <TypingText>Ian unifies user needs with computational thinking.</TypingText>
        <p>
          Currently designing decision support systems for the Air Force in DSTA.
          <br />
          <br />
          Previously a Visual Arts Scholar @ NUS.
          <br />
          <br />
          Studied Computer Science and UX Design.
        </p>
      </section>
      <section>
        <h1>
        Selected Works
        </h1>
        <div>Segmented control: UX Design / UX Research / ARVR Development</div>
        <p>
          projects card component is Projects.tsx line 8, simply uncomment and add css (links that wrap divs)
        </p>
        <ul>
          <li>header</li>
          <li>tag: design type • design type, context (eg take-home task, hackathon, coursework, internship)</li>
          <li>one-liner description of proj objective</li>
          <li>image</li>
        </ul>
        <p>
          button: Browse all projects
        </p>
      </section>
      <section>
        <h1>
        Hi! I'm Ian 👋
        </h1>
        <h3>
          I'm a designer that can code.
        </h3>
        <p>
          I specialise in rigorous user research and designing user-centered solutions that are technically feasible. // This paragraph is the same as the first paragraph in the About page.
        </p>
        <p>
          button: Read more about me
        </p>
      </section>
    </div>
  )
}

function Header({ title }) { // props is an object with a property "title".
  // props is { title: "I love Vim a LOT!!" } javascript object
  // instead of 'props', use named destructuring in the params to get the value
  // usage: 
  // <Header title="Ian unifies user needs with computational thinking."/>
  return (
    <h1>
      {title}
    </h1>
  )
}

// note to self, Shift-Shift % is how to search for text across files for my vscode
