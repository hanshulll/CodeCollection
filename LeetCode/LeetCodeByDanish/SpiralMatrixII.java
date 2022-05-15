package LeetCode;

import java.util.Arrays;

/*
https://leetcode.com/problems/spiral-matrix-ii/
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
 */
public class SpiralMatrixII {
    public static void main(String[] args) {
        int n = 4;
        int[][] matrix = generateMatrix(n);

        for(int[] i : matrix){
            System.out.println(Arrays.toString(i));
        }
    }
    public static int[][] generateMatrix(int n) {
        int ttl = n*n;
        int count =1;

        int[][] matrix = new int[n][n];
        int cst = 0;
        int cend = n-1;
        int rst = 0;
        int rend = n-1;

        while (count <= ttl) {
            for (int i = cst; i <= cend; i++) {

                matrix[rst][i] = count;
                count++;
            }
            rst++;

            // form up to down.
            for (int i = rst; i <= rend; i++) {

                matrix[i][cend] = count;
                count++;
            }
            cend--;

            // form right to left in down.
            for (int i = cend; i >= cst; i--) {

                matrix[rend][i] = count;
                count++;
            }
            rend--;

            for (int i = rend; i >= rst; i--) {

                matrix[i][cst] = count;
                count++;
            }
            cst++;
        }
        return matrix;
    }
}
