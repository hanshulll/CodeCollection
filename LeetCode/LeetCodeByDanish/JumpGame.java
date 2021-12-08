package LeetCode;

import org.jetbrains.annotations.Contract;

/*
https://leetcode.com/problems/jump-game/
You are given an integer array nums. You are initially positioned at the array's first index,
 and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what.
Its maximum jump length is 0, which makes it impossible to reach the last index.
 */
public class JumpGame {
    public static void main(String[] args) {
        int[] nums = {2,3,1,1,4};
      //  int[] nums = {3,2,1,0,4};
        System.out.println(canJump(nums));

    }

    public static  boolean canJump(int[] nums) {
        int n=nums.length;
        int dp[]=new int[n+1];
        dp[0]=nums[0];
        if(nums[0]==0 && n==1)return true;
        int t=0;
        for(int i=1;i<=n;i++){
            if(dp[i-1]-1>=0){
                dp[i]=Math.max(dp[i-1]-1,nums[i-1]);
                t++;
            }
            else{
                return false;
            }
        }
        return true;
    }
}
