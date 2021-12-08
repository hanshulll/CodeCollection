package LeetCode;

import java.util.Arrays;

/*
https://leetcode.com/problems/set-matrix-zeroes/
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 */
public class SetMatrixZero {
    public static void main(String[] args) {
//        int[][] matrix = {
//                {1,1,1},
//                {1,0,1},
//                {1,1,1}
//        };

//        int[][] matrix = {
//                {0,1,2,0},
//                {3,4,5,2},
//                {1,3,1,5}
//        };

        int[][] matrix = {{0 ,1 }};

        for(int[] i : matrix){
            System.out.println(Arrays.toString(i));
        }

        setZeroes(matrix);
        System.out.println("Ater setting 0");
        for(int[] i : matrix){
            System.out.println(Arrays.toString(i));
        }
    }

    public static void setZeroes(int[][] matrix) {

        int[][] fre = new int[matrix.length][matrix[0].length];
            for(int i = 0 ; i<matrix.length ; i++){
                for(int j = 0 ; j<matrix[i].length ; j++){
                    if(matrix[i][j] == 0){
                    fre[i][j] ++;
                    }
                }
            }
        // setting0(matrix, i1,j1);
           for(int i = 0 ; i<fre.length ; i++){
               for (int j = 0 ; j<fre[i].length ; j++){
                   if(fre[i][j] == 1){
                       setting0(matrix , i , j);
                   }
               }
           }
    }

    public static void setting0(int[][] matrix , int i , int j){
        int up  = i;
        int dn  = i ;
        int lf =j ;
        int rt = j;

        // for up
        while( up >= 0){
            matrix[up][j] = 0;
            up--;
        }

        // for down.
        while( dn < matrix.length){
            matrix[dn][j] = 0;
            dn++;
        }

        // for left.
        while( lf >= 0){
            matrix[i][lf] = 0;
            lf--;
        }

        // for right
        while( rt < matrix[i].length){
            matrix[i][rt] = 0;
            rt++;
        }

    }

}
