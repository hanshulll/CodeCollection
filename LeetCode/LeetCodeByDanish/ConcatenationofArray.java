package LeetCode;
/*
https://leetcode.com/problems/concatenation-of-array/
Given an integer array nums of length n,
 you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.
Return the array ans.

Example 1:

Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
- ans = [1,2,1,1,2,1]
Example 2:

Input: nums = [1,3,2,1]
Output: [1,3,2,1,1,3,2,1]
Explanation: The array ans is formed as follows:
- ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
- ans = [1,3,2,1,1,3,2,1]
 */

import java.lang.reflect.Array;
import java.util.Arrays;

public class ConcatenationofArray {

    public static void main(String[] args) {
        int[] nums = {1,3,2,1};
        int[] ans = getConcatenation(nums);
        System.out.println(Arrays.toString(ans));
    }

    public static int[] getConcatenation(int[] nums) {
        int sz = 2*nums.length;
        int[] ans = new int[sz];

        for (int i = 0  , j = i+ nums.length; i< nums.length ; i++ , j++){

            ans[i] = nums[i];
            ans[j] = nums[i];
        }

      return ans;
    }
}
