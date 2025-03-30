// Main layout of application
// Used for UI elements that are shared across all pages
/**
 * On navigation, layouts preserve state, remain interactive, and do not rerender.
 * source: https://nextjs.org/docs/app/getting-started/layouts-and-pages
 */
import './global.css'
import type { Metadata } from 'next'
import { Navbar } from './components/nav'
import { Analytics } from '@vercel/analytics/react'
import { SpeedInsights } from '@vercel/speed-insights/next'
import Footer from './components/footer'
import { baseUrl } from './sitemap'
import Head from 'next/head'

// generally in Typescript, var: Type is the syntax, opposite of C-langs
// interfaces are like typed classes for objects
// tho JS has their own Classes, which have a constructor
// their use is to specify default props and values 

// this object implements the interface Metadata
export const metadata: Metadata = {
  metadataBase: new URL(baseUrl),
  title: {
    default: 'Portfolio - Ian Hong',
    template: '%s | Next.js Portfolio Starter',
  },
  description: 'Ian Hong is a UX designer and developer who graduated from Computer Science at the National University of Singapore.',
  openGraph: {
    title: 'Portfolio - Ian Hong',
    description: 'Ian Hong is a UX designer and developer who graduated from Computer Science at the National University of Singapore.',
    url: baseUrl,
    siteName: 'Portfolio - Ian Hong',
    locale: 'en_US',
    type: 'website',
  },
  robots: {
    index: true,
    follow: true,
    googleBot: {
      index: true,
      follow: true,
      'max-video-preview': -1,
      'max-image-preview': 'large',
      'max-snippet': -1,
    },
  },
  icons: {
    icon: 'favicon.svg',
  },
}

const cx = (...classes) => classes.filter(Boolean).join(' ')

/*
      className={cx(
        'text-black bg-white dark:text-white dark:bg-black',
        GeistSans.variable,
        GeistMono.variable)

      <body className="antialiased max-w-xl mx-4 mt-8 lg:mx-auto">
        <main className="flex-auto min-w-0 mt-6 flex flex-col px-2 md:px-0">
*/
// the colon is typescript to specify the type
// RootLayout must contain html and body tags, and children
export default function RootLayout({ children, }: { children: React.ReactNode }) {
  return (
    <html lang="en" >
      <body>
        <main>
          <Navbar />
          {children}
          <Footer />
          <Analytics />
          <SpeedInsights />
        </main>
      </body>
    </html>
  )
}
