/*
Question Link : https://leetcode.com/problems/set-matrix-zeroes/

73. Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.

*/

// Solution (2 solutions)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*int R=matrix.size();
        int C=matrix[0].size();
        bool row[R];
        bool col[C];

        for (int i = 0; i < R; i++){        // Initialize all values of row[] as 1
            row[i] = 1;
        }
        for (int i = 0; i < C; i++){        // Initialize all values of col[] as 1
            col[i] = 1;
        }

        // Store the rows and columns to be marked as 0 in row[] and col[] arrays
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                if (matrix[i][j] == 0){
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        // Modify the input matrix using the above constructed row[] and col[] arrays
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j++){
                if ( row[i] == 0 || col[j] == 0 ){
                    matrix[i][j] = 0;
                }
            }
        }

        Time Complexity : O(m * n)
        Space Complexity : O(m + n)
        */

        int R=matrix.size();
        int C=matrix[0].size();
        // variables to check if there are any 0 in first row and column
        bool row_flag = true;
        bool col_flag = true;

        // updating the first row and col if 0 is encountered
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (i == 0 && matrix[i][j] ==0){
                    row_flag = false;
                }
                if (j == 0 && matrix[i][j] == 0){
                    col_flag = false;
                }
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // Modify the input matrix using first row and first column of matrix
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (row_flag == false) {            // modify first row if there was any 0
            for (int i = 0; i < C; i++) {
                matrix[0][i] = 0;
            }
        }

        if (col_flag == false) {            // modify first col if there was any 0
            for (int i = 0; i < R; i++) {
                matrix[i][0] = 0;
            }
        }

        /*
        Time Complexity : O(m * n)
        Space Complexity : O(1)
        */
    }    
};

/*
Sample Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Sample Output: [[1,0,1],[0,0,0],[1,0,1]]
*/
