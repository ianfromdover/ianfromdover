# Portfolio - Ian Hong

I want to learn webdev and host my portfolio on this website.

```bash
# To run
pnpm dev
```

## Roadmap

1. √ Fix the blog pages not loading before deploying next by merging to prod
2. √ Add Next
3. learn CSS
4. Add SCSS after learning CSS to customise components
5. Convert pages to typescript using this prompt in Gemini `list common changes when going from javascript to typescript using next.js`
5. Add `MDX` or `remark` to create pages from markdown
6. Build my figma app in react
7. Do some fun code graphics thingy (scroll makes a bendy text scroll?)
8. Learn three.js and add some 3D model


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
- RSS Feed
- Dynamic OG images
- Syntax highlighting
- Vercel Speed Insights / Web Analytics
