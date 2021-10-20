/*
******************* Insertion Sort Algorithm *********
Builds up the sort by gradually creation a larger left half which is always sorted
# Example:
[5, 4, 3, 2, 1]
[3, 4, 4, 1, 2]
[3, 4, 5, 1, 2]
[1, 3, 4, 5, 2]
[1, 2, 3, 4, 5]
*/

/*
Pseudo Code
1. Start by picking the second element in the array
2. Now compare the second element with the one before it and swap if necessary
3. Continue to the next element and if it is in the incorrect order, iterate through the sorted portion(i.e. the left side) to place the element in the correct place
4. Repeat until the array is sorted
*/

function insertionSort(arr) {
  for (let i = 1; i < arr.length; i++) {
    let currentVal = arr[i];
    for (let j = i - 1; j >= 0 && arr[j] > currentVal; j--) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = currentVal;
  }
  return arr;
}

insertionSort([2, 1, 9, 76, 4]);
