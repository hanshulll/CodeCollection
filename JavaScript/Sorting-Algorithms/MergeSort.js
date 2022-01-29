// Merge sort has a time complexity of O(nlogn) and space complexity of O(n)
// Works on the idea that an array of size less than 2 is sorted by default
// Uses recursive approach to divide a larger array into equal sized subarrays, and merges them to get to a sorted array
// More info here https://www.geeksforgeeks.org/merge-sort/

// Contributed by Rajat(@Rajatm544)

// A function to merge 2 subarrays into a single sorted array
function merge(arr1, arr2) {
    // two pointers for the first index of both arrays
    let i = 0,
      j = 0;
  
    let res = [];
  
    // loop until one of these pointers has reached the end of their respective array length
    while (i < arr1.length && j < arr2.length) {
      // Compare the array elements at the pointer index, push the smaller of two to the result array and increment that array's pointer
      if (arr1[i] < arr2[j]) {
        res.push(arr[i]);
        i++;
      } else {
        res.push(arr2[j]);
        j++;
      }
      res.push(arr2[j]);
    }
  
    // If arr1's elements are all pushed to the result, push the entire arr2 to the result jth index onwards
    // add rest of the remaining subarray
    while (i < arr1.length) {
      res.push(arr1[i]);
      i++;
    }
  
    // If arr2 is already empty, push the remaining element of arr1 to the result as it is
    while (j < arr2.length) {
      res.push(arr2[j]);
      j++;
    }
    return res;
  }
  
  // function to recursively split the input array into 2 equal halves and merge them using merge()
  function mergeSort(arr) {
    if (arr.length <= 1) return arr;
    // Splitting into two halves
    let mid = Math.floor(arr.length / 2);
    let left = mergeSort(arr.slice(0, mid));
    let right = mergeSort(arr.slice(mid));
    // merging the two sorted halves
    return merge(left, right);
  }