package LeetCode;
/*
https://leetcode.com/problems/jump-game-ii/
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.
Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 */
public class JumpGameII {
    public static void main(String[] args) {
        int[] arr = {3,3,0,2,1,2,4,2,0,0};
        System.out.println(jump(arr));

    }
    public static  int jump(int[] nums ) {
        int[] dp= new int[nums.length];


        for(int i = dp.length-2 ; i>=0 ; i--){
            int min = Integer.MAX_VALUE-1;
            for(int jump = 1 ; jump<=nums[i]; jump++){
                if(i+jump < dp.length) {
                    min = Math.min(min , dp[i+jump]);
                }
            }
            dp[i] = 1 + min;
        }


        return dp[0];


    }
}
