package LeetCode;
import java.util.*;
/*
https://leetcode.com/problems/spiral-matrix/
Given an m x n matrix, return all elements of the matrix in spiral order.
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Input : [[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]
Output : [1,2,3,4,5,10,15,20,25,24,23,22,21,16,11,6,7,8,9,14,19,18,17,12,13]
 */
public class SpiralMatrix {
    public static void main(String[] args) {
//        int[][] matrix = {
//                {1,2,3,4},
//                {5,6,7,8},
//                {9,10,11,12}
//        };

        int[][] matrix = {
                {1,2,3,4,5},
                {6,7,8,9,10},
                {11,12,13,14,15},
                {16,17,18,19,20},
                {21,22,23,24,25}
        };

        List<Integer> ans= spiralOrder(matrix);
        for (int i = 0; i < ans.size() ; i++) {
            System.out.print(ans.get(i) + " ");
        }
    }
    public static List<Integer> spiralOrder(int[][] matrix) {
        int ttl = matrix.length * matrix[0].length;
        int count =0;
      //  System.out.println(ttl);
        int rst = 0;
        int rend = matrix.length-1;
        int cst = 0;
        int cend = matrix[0].length-1;
        List<Integer> ans = new ArrayList<>();


           while (count < ttl) {
               // for upper left to right.
               for (int i = cst; i <= cend; i++) {
                   if(count == ttl){
                       return ans;
                   }
                   ans.add(matrix[rst][i]);
                   count++;
               }
               rst++;

               // form up to down.
               for (int i = rst; i <= rend; i++) {
                   if(count == ttl){
                       return ans;
                   }
                   ans.add(matrix[i][cend]);
                   count++;
               }
               cend--;

               // form right to left in down.
               for (int i = cend; i >= cst; i--) {
                   if(count == ttl){
                       return ans;
                   }
                   ans.add(matrix[rend][i]);
                   count++;
               }
               rend--;

               for (int i = rend; i >= rst; i--) {
                   if(count == ttl){
                       return ans;
                   }
                   ans.add(matrix[i][cst]);
                   count++;
               }
               cst++;


           }

        return ans;
    }
}


