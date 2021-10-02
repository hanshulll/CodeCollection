/*
* 'Selection sort' is an algorithm to sort an unsorted array into either ascending or descending order.
* In every iteration, the largest element in unsorted array is selected and moved to the correct index in sorted subarray.
* We can select the smallest element and move it the sorted subarray also. But in the following code I have chosen the former.
* Time complexity :
            Best case : O(n^2)
            Worst case : O(n^2)
*/

import java.util.Arrays;

public class SelectionSort {
    public static void main(String[] args) {
        int[] array = {7, 5, 6, 3, 2, 1, 4, 10};
        System.out.println(Arrays.toString(selectionSort(array)));
    }

    static int[] selectionSort(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            int key = Integer.MIN_VALUE;
            int indexOfMax = 0;
            for (int j = 0; j <= array.length - i - 1; j++) {
                if (array[j] > key) {
                    key = array[j];
                    indexOfMax = j;
                }
            }
            int temp = array[array.length - i - 1];
            array[array.length - i - 1] = key;      // The largest element is being moved to the sorted subarray
            array[indexOfMax] = temp;
        }
        return array;
    }
}