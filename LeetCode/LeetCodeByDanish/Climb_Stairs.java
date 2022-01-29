package LeetCode;
/*
https://leetcode.com/problems/climbing-stairs/
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 */
public class Climb_Stairs {
    public static void main(String[] args) {
        int n= 44;
        System.out.println(climbStairs(n));

    }
    public static int climbStairs(int n) {
        int[] dp = new int[n+1];
//         if(n==0){
//             return 1;
//         }
//         if(n <0) return 0;

//         if(dp[n] !=0){
//             return dp[n];
//         }

//         int cl = climbStairs(n-1) + climbStairs(n-2);
//         dp[n] = cl;
//         return cl;
        dp[0]= 1;
        dp[1] = 1;

        for(int i = 2 ; i<= n ; i++){

                dp[i] = dp[i-1]+dp[i-2];

        }
        return dp[n];

    }
}
