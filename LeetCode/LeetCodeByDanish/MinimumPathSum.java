package LeetCode;
/*
https://leetcode.com/problems/minimum-path-sum/
Given a m x n grid filled with non-negative numbers,
 find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 */
public class MinimumPathSum {
    public static void main(String[] args) {
        int[][] arr = {
                {1,3,1},
                {1,5,1},
                {4,2,1}
        };
        System.out.println(minPathSum(arr));

    }
    public static  int minPathSum(int[][] arr) {
        int n = arr.length;
        int m = arr[0].length;
        int[][] dp = new int [n][m];

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = m-1 ; j>=0 ; j--){
                if(i == n-1 && j== m-1){
                    dp[i][j] = arr[i][j];
                }
                else if(i == n-1){
                    dp[i][j] = dp[i][j+1] + arr[i][j];
                }
                else if(j== m-1){
                    dp[i][j] = dp[i+1][j] +arr[i][j];
                }
                else{
                    dp[i][j] = Math.min(dp[i+1][j] , dp[i][j+1]) + arr[i][j];
                }
            }

        }
        return dp[0][0];

    }
}

