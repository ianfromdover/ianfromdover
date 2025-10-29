// This hook manages the logic for moving the selected index.

import { useState, useEffect, useCallback } from 'react';

/**
 * Custom hook to handle up/down arrow key navigation for a list.
 * @param {number} listSize The total number of items in the list.
 * @returns {[number]} An array containing the current focused index.
 */
const useArrowKeyNavigation = (listSize) => {
  // 0 is the index of the first item ('work')
  const [focusedIndex, setFocusedIndex] = useState(0);

  const handleKeyDown = useCallback((event) => {
    // Check if the focus is on an input or textarea, and if so, don't handle the event
    if (document.activeElement?.tagName === 'INPUT' || document.activeElement?.tagName === 'TEXTAREA') {
        return;
    }

    const { key } = event;

    if (key === 'ArrowDown') {
      event.preventDefault(); // Prevents page scrolling
      setFocusedIndex(prevIndex => {
        // Wrap around: if at the end, go to the start (0)
        return (prevIndex + 1) % listSize;
      });
    } else if (key === 'ArrowUp') {
      event.preventDefault(); // Prevents page scrolling
      setFocusedIndex(prevIndex => {
        // Wrap around: if at the start (0), go to the end (listSize - 1)
        return prevIndex === 0 ? listSize - 1 : prevIndex - 1;
      });
    }
  }, [listSize]); // Recreate if listSize changes

  useEffect(() => {
    // Attach the event listener to the entire document
    document.addEventListener('keydown', handleKeyDown);

    // Clean up the event listener on unmount
    return () => {
      document.removeEventListener('keydown', handleKeyDown);
    };
  }, [handleKeyDown]);

  return [focusedIndex];
};

export default useArrowKeyNavigation;
