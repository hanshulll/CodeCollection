/*
  Created by Mitadru Datta

  LeetCode Problem :- 74. Search a 2D Matrix
  LeetCode url :- https://leetcode.com/problems/search-a-2d-matrix/
*/

/*
  Problem Statement :-

  Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
  - Integers in each row are sorted from left to right.
  - The first integer of each row is greater than the last integer of the previous row.
*/

/*
  Constraints:

  - m == matrix.length
  - n == matrix[i].length
  - 1 <= m, n <= 100
  - -104 <= matrix[i][j], target <= 104
*/

class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {

        for(int i = 0; i < matrix.length; i++) {
            if(matrix[i][0] <= target && matrix[i][matrix[i].length - 1] >= target) {   // Checks whether it is possible to find the target in the particular row
                return binarySearch(matrix[i], target);  // Search for the target in the row by implementing Binary Search
            }
        }

        return false;

    }

    public boolean binarySearch(int[] arr, int target) {   // If target found in the given row, then return true, else return false
        int start = 0;
        int end = arr.length - 1;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(arr[mid] > target) {
                end = mid - 1;
            }else if(arr[mid] < target) {
                start = mid + 1;
            }else {
                return true;
            }
        }

        return false;

    }
}

/*
  Time Complexity :- O(n + logn) = O(n)
                    The loop runs for n times (n is the total number of rows).
                    If there is a possibility of finding the target in a particular row, then
                    Binary Search algorithm is implemented for only once which has a
                    time complexity og O(logn)

  Space Complexity :- O(1)
*/
