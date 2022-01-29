/**
  --- HEAPSORT ---
  Heapsort is a comparison-based sorting algorithm. Heapsort can be thought of as an improved selection sort: like selection sort, 
  Heapsort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest 
  element from it and inserting it into the sorted region. Unlike selection sort, heapsort does not waste time with a linear-time scan of 
  the unsorted region; rather, Heapsort maintains the unsorted region in a heap data structure to more quickly find the largest element in each step.
  
*/

//First we'll make our sorting function
const heapsort = (arr) => {
  //We'll use the spread operator (...) to clone the original array, arr.
  const a = [...arr];
  //Also we're going to use closures to declare a variable, l, and a function heapify.
  let l = a.length;

  //Then we'll use a for loop and Math.floor() in combination with heapify to create a max heap from the array.
  const heapify = (a, i) => {
    const left = 2 * i + 1;
    const right = 2 * i + 2;
    let max = i;
    if (left < l && a[left] > a[max]) max = left;
    if (right < l && a[right] > a[max]) max = right;
    if (max !== i) {
      [a[max], a[i]] = [a[i], a[max]];
      heapify(a, max);
    }
  };
  //Finally we'll use a for loop to repeatedly narrow down the considered range, using heapify and swapping values as necessary in order to sort the cloned array.
  for (let i = Math.floor(l / 2); i >= 0; i -= 1) heapify(a, i);
  for (i = a.length - 1; i > 0; i--) {
    [a[0], a[i]] = [a[i], a[0]];
    l--;
    heapify(a, 0);
  }
  return a;
};

//EXAMPLE
heapsort([6, 3, 4, 1]); // [1, 3, 4, 6]
