import { BlogPosts } from 'app/components/posts'
import Link from 'next/link'

export const metadata = {
  title: 'Work',
  description: 'Projects i\'ve completed.',
}

// <!-- h1 className="font-semibold text-2xl mb-8 tracking-tighter" -->
export default function Page() {
  return (
    <section>
      <h1>Work</h1>
      <ul>
        <li>
          <p>
            Hairlingo: Designed a mobile AR app that makes discovering, visualising, and obtaining hairstyles easier. Won Huawei Interaction Design Award amongst 28 teams, cash prize
          </p>
          <Link 
            href={'https://www.behance.net/gallery/188772027/HairLingo-AR-Hairstyle-App-UIUX-Design'}
          >
            See on Behance
          </Link>
        </li>
        <li>
          <p>
            Capsule Cat: Lead user research for a third-person shooting game where 2 players cooperate to control the same character. Won Gold amongst 10 teams in exhibition, landing an offer for the Singtel Management Associate Programme
          </p>
          <Link 
            href={'https://www.behance.net/gallery/188772637/Capsule-Cat-Multiplayer-Game-UX-Design?tracking_source=project_owner_other_projects'}
          >
            See on Behance
          </Link>
        </li>
        <li>
          <p>
            National University of Singapore Jazz Band Annual Recruitment Campaign: I conducted UX research, branding and social media marketing to save the club from closing down. I increased auditionees by 170% more than tha previous year, and set the standard for future publicity heads.
          </p>
          <Link 
            href={'https://www.behance.net/gallery/188772837/Jazz-Band-Campaign-UX-Research-Branding-Marketing?tracking_source=project_owner_other_projects'}
          >
            See on Behance
          </Link>
        </li>
        <li>
          <p>
            Shopee Assignment Valentine's day mobile landing page design: I increased product discoverability beyond a user's current browsing behaviour.
          </p>
          <Link 
            href={'https://www.behance.net/gallery/220194601/Shopee-Valentines-Day-Landing-Page-UIUX-Design'}
          >
            See on Behance
          </Link>
        </li>
        <li>
          <p>
            Dragon's Den: Designed a desktop video conferencing app that makes it easier for friends to play Dungeons and Dragons
          </p>
        </li>
      </ul>
      <BlogPosts />
    </section>
  )
}
