// Main page of the application
// by default, in next.js, all components are server components and are stateless

/*
      <h1 className="mb-8 text-2xl font-semibold tracking-tighter">
      <p className="mb-4">
      <div className="my-8">
*/
export default function Page() { // the export default says this is the main component to render for the page

  return (
    <div>
      <section>
        <Header title="Ian unifies user needs with computational thinking."/>
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
        <h3>
        Selected Works
        </h3>
        <p>
          the home page will be the main project page. the Work footer will be an anchor link to this section. Change the blog page to a Work page.
        </p>
        <p>
          make projects component, with cards
        </p>
        <ul>
          <li>header</li>
          <li>tag: design type • design type, context (eg take-home task, hackathon, coursework, internship)</li>
          <li>one-liner description of proj objective</li>
          <li>image</li>
        </ul>
      </section>
      <section>
        <h3>
        Hi! I'm Ian 👋
        </h3>
        <p>
          (subheader) I'm a something that defines my identity to employers.
        </p>
        <p>
          This will be a concise version of the About section, relevant to recruiters. I specialise in rigorous user research and designing user-centered solutions that are technically feasible. // This paragraph is the same as the first paragraph in the About page.
        </p>
        <p>
          button: read more about me
        </p>
      </section>
    </div>
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

// note to self, Shift-Shift % is how to search for text across files for my vscode
