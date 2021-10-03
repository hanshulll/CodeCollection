/**Bucket sort, or bin sort, is a sorting algorithm that works by distributing the elements of an array into a number of buckets.
Each bucket is then sorted individually, either using a different sorting algorithm, or by recursively applying the bucket sorting algorithm.
It is a distribution sort, a generalization of pigeonhole sort, and is a cousin of radix sort in the most-to-least significant digit flavor.
Bucket sort can be implemented with comparisons and therefore can also be considered a comparison sort algorithm.
*/

//First we'll make our function to sort
const bucketSort = (arr, size = 5) => {
  //We use Math.min(), Math.max() and the spread operator (...) to find the minimum and maximum values of the given array.
  const min = Math.min(...arr);
  const max = Math.max(...arr);

  //Then we use Array.from() and Math.floor() to create the appropriate number of buckets (empty arrays).
  const buckets = Array.from(
    { length: Math.floor((max - min) / size) + 1 },
    () => []
  );

  //Then we use Array.prototype.forEach() to populate each bucket with the appropriate elements from the array.
  arr.forEach((val) => {
    buckets[Math.floor((val - min) / size)].push(val);
  });

  //And finally we use Array.prototype.reduce(), the spread operator (...) and Array.prototype.sort() to sort each bucket and append it to the result.
  return buckets.reduce((acc, b) => [...acc, ...b.sort((a, b) => a - b)], []);
};

//EXAMPLE
bucketSort([6, 3, 4, 1]); // [1, 3, 4, 6]
