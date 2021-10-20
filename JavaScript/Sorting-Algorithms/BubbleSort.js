/* Bubble Sort is a sorting algorithm that 'bubbles' sorted values to the top
For Sorting an array of numbers from least to greatest, 
Bubble Sort sorts by moving larger values to the end as it iterates through array */

// Implement a swap helper function that we will use in both Bubble Sort and Selection Sort

/* ****************** PseudoCode ***************
1. Start looping from with a variable called i the end of the array towards the beginning
2. Start an inner loop with a variable called j from the beginning until i-1
3. If arr[j] is greater than arr[j + 1], swap those values!
4. Return the sorted array
*/

const swap = (arr, i, j) => {
  let temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
};

// bubble sort works by having sorted data accumulate at end of array

function bubbleSort(arr) {
  for (let i = 0; i < arr.length; i++) {
    for (let j = 0; j < arr.length - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr, j, j + 1);
      }
    }
  }
  return arr;
}

bubbleSort([37, 45, 29, 8]);

// Big 0 => O(n^2)
