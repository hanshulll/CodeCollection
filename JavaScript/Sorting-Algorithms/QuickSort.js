// Quick sort works by choosing a pivot element, and making sure that all the elements to the left of
// the pivot element is less than the pivot(not necessarily sorted, they just need to be  less than the pivot)
// and that all the elements to the right of the pivot are all greater than it.

// The best and average time complexity is O(nlogn). But the worst case scenario for the time complexity is O(n^2).
// The space complexity is O(log n).

// Contributed by Rajat(@Rajatm544)

function pivot(arr, start = 0, end = arr.length - 1) {
  // choose an arbitraty pivot element
  let pivot = arr[start];
  let swapIdx = start;

  for (let i = start + 1; i <= end; i++) {
    // If current element is lesser than our pivot element,increment the pivot index
    if (arr[i] < pivot) {
      swapIdx++;

      // Swap current element with the element at the new pivot index
      [arr[i], arr[swapIdx]] = [arr[swapIdx], arr[i]];
    }
  }

  // Swap the pivot element with the element at the swapIndex index
  [arr[swapIdx], arr[start]] = [arr[start], arr[swapIdx]];
  return swapIdx; // Return the index of the pivot element after swapping
}

// funtion to recursively obtain various pivot indices and theryby sort the array
function quickSort(arr, left = 0, right = arr.length - 1) {
  // Base case is that the left and right pointers don't overlap, after which we'll be left with an array of 1 item
  if (left < right) {
    let pivotIndex = pivot(arr, left, right);
    // For left subarray, which is everything to the left of the pivot element
    quickSort(arr, left, pivotIndex - 1);
    // For the right sub array, which is everything to the right of the pivot element
    quickSort(arr, pivotIndex + 1, right);
  }
  // Return the array, when it's of length 1 i.e, left === right
  return arr;
}
