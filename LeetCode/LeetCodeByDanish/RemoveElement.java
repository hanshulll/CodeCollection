package LeetCode;
import java.util.*;
/*
https://leetcode.com/problems/remove-element/
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
 The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages,
 you must instead have the result be placed in the first part of the array nums.
  More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result.
  It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 2.
It does not matter what you leave beyond the returned k (hence they are underscores).
 */
public class RemoveElement {
    public static void main(String[] args) {
        int[] num = {3,2,2,3};
        System.out.println(removeElement(num , 3));
        System.out.println(fact(5));
    }


    public static int removeElement(int[] nums, int val) {
        int count = 0;
        Arrays.sort(nums);
        for(int i = 0 ; i<nums.length ; i++){
            if(nums[i] != val){
                count++;
            }
        }



    return count;
    }


    // Program to find factorial.
    public static int fact(int n){
        return (n==0 || n==1) ? 1 : n*fact(n-1);
    }

}
