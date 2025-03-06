'use client';
import { useState } from "react";
import styles from 'app/components/like-button.module.css'
export default function LikeButton() {
  // this function is in the same function as the component,
  // and is place before the return statement
  // reactEvents are camelCased, like for onClick

  const [likes, setLikes] = useState(0); // init value = 0
  /**
   * State operates in 3 steps
   * 1. Trigger (when the set function is called)
   * 2. Render
   * 3. Commit to DOM (display)
   */

  function handleClick() {
    console.log("clicked");
    // setLikes(likes + 1); // triggers a re-render. 
    // It doesn't update it in the code thats alr running tho
    // to do that, pass an updater function
    // this lets you queue multiple state updates
    setLikes(l => l + 1);
  }

  // for CSS Modules, instead of dash-naming which is normal, use camelCase
  // justification https://github.com/facebook/create-react-app/issues/11155#issuecomment-870692095
  return (
    <button className={styles.likeButton} onClick={handleClick}>{likes} others also like this</button>
  )
}

// to handle state of arrays and objects, you need to:
// create a new array(or copy one) and then set it as the new one

// array can use .map(currElem => currElem + 1) to return a new list 
// where + 1 is modification

// read more about handling state of arrays and objects
// https://react.dev/learn/adding-interactivity

