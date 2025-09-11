# Portfolio - Ian Hong

I want to learn webdev and host my portfolio on this website.

```bash
# To run
pnpm dev
```

- each folder has a page.tsx where you can edit it.
- their .module.css files are placed beside it.

## Roadmap

1. √ Fix the blog pages not loading before deploying next by merging to prod
2. √ Add Next
3. Add content from Portfolio 15 Jan Ian Hong.pdf
3. Add movement easing curves
3. learn CSS and how its related to the figma controls
4. Add SCSS after learning CSS to customise components
5. Convert pages to typescript using this prompt in Gemini `list common changes when going from javascript to typescript using next.js`
5. Add `MDX` to create pages from markdown
  - learn [MDX - markdown for the component era](https://mdxjs.com/)
6. Build my figma app in react
7. Do some fun code graphics thingy (scroll makes a bendy text scroll?)
8. Learn three.js and add some 3D model

## To Read
- fix the subpages not rendering when getting there. it's preventing deployment on prod
- find: Figma controls and their related CSS
  - literally just make boxes and autolayout in figma then copy in editor
- css cheatsheet https://htmlcheatsheet.com/css/
- practices
  - frontendmentor challenges (projects): 
    - [basic css](https://www.frontendmentor.io/learning-paths/getting-started-on-frontend-mentor-XJhRWRREZd/steps/67c99f43a98e92cdab2a5ce4/article/read)
    - [advanced css (really really good)](https://www.frontendmentor.io/learning-paths/advanced-css-techniques-vdOtKjIC4V)
  - Flexbox Froggy, learn flexbox https://flexboxfroggy.com/
  - CSS Diner, learn selectors https://flukeout.github.io/
  - CSS Garden, learn grids https://cssgridgarden.com/
- one-by-one explainers
- https://web.dev/learn/css
- https://www.geeksforgeeks.org/how-to-learn-css-in-21-days/
- [1-week free trial frontend masters](https://frontendmasters.com/learn/css/)
- style guide https://airbnb.io/javascript/react/#basic-rules

## File Structure

``` bash
.
├── README.md
├── app
│   ├── FOLDER blog // route
│   ├── FOLDER components // should probably move this to ui
│   ├── global.css // should probably move this to ui
│   ├── layout.tsx
│   ├── FOLDER lib // reusable utility and data fetching fns
│   ├── not-found.tsx
│   ├── FOLDER og // dynamic images???
│   ├── page.tsx
│   ├── robots.ts
│   ├── FOLDER rss // feed???
│   ├── sitemap.ts
│   └── FOLDER ui // components
├── next-env.d.ts
├── package.json
├── pnpm-lock.yaml
├── FOLDER public // for static assets like images and JSON
└── tsconfig.json
```

## Learn More

Where I learnt Next.JS:

- [Next.js Documentation](https://nextjs.org/docs)
- [Learn Next.js](https://nextjs.org/learn) - an interactive Next.js tutorial

## Template

Cloned from:
<https://vercel.com/new/ian-hongs-projects-a7a7a726/templates/next.js/portfolio-starter-kit>

- MDX and Markdown support // get MDX working
- Optimized for SEO (sitemap, robots, JSON-LD schema)
- Dynamic OG images
- Syntax highlighting
- Vercel Speed Insights / Web Analytics
