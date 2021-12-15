package LeetCode;

import java.util.Arrays;

/*
https://leetcode.com/problems/running-sum-of-1d-array/
Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).
Return the running sum of nums.
Example 1:

Input: nums = [1,2,3,4]
Output: [1,3,6,10]
Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
 */
public class SumOf1DArray {
    public static void main(String[] args) {
        int[] nums = {1,2,3,4};
        int[] ans = runningSum(nums);
        System.out.println(Arrays.toString(ans));


    }
    public static int[] runningSum(int[] nums) {
        int[] ans = new int[nums.length];
        int sum = 0;
        int j = 0;
       while ( j < nums.length){

          ans[j] = nums[j] +sum;
           sum = ans[j];
          j++;

       }
        return  ans;
    }
}
