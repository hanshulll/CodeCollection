package LeetCode;

/*
https://leetcode.com/problems/search-insert-position/
Given a sorted array of distinct integers and a target value,
return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1
 */
public class SearchInsertPosition {
    public static void main(String[] args) {
//        int[] arr = {1,2,3,4,6};
//        int target= 5;

        int[] arr = {1,3,5,6};
        int target = 2;
//        int[] arr = {1};
//        int target = 1;

//        int[] arr = {1,3};
//        int target = 0;
       // System.out.println(searchInsert(arr , target));
        System.out.println(searchInsert2(arr,target));

    }

    public static  int searchInsert2(int[] nums, int target) {

        int start = 0;
        int end = nums.length-1;


        while(start <= end)
        {
            int mid = start + (end-start) / 2;
            // System.out.println(mid);
            if(nums[mid] > target)
            {
                end = mid-1;
            }
            else if (nums[mid] < target)
            {
                start = mid+1;
                // ans = start;
            }
            else{
                return mid;
            }
        }
        return start;
    }
}
