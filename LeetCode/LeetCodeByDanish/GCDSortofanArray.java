package LeetCode;
/*
https://leetcode.com/problems/gcd-sort-of-an-array/
You are given an integer array nums, and you can perform the following operation any number of times on nums:

Swap the positions of two elements nums[i] and nums[j] if gcd(nums[i], nums[j]) > 1 where gcd(nums[i], nums[j]) is the greatest common divisor of nums[i] and nums[j].
Return true if it is possible to sort nums in non-decreasing order using the above swap method, or false otherwise.



Example 1:

Input: nums = [7,21,3]
Output: true
Explanation: We can sort [7,21,3] by performing the following operations:
- Swap 7 and 21 because gcd(7,21) = 7. nums = [21,7,3]
- Swap 21 and 3 because gcd(21,3) = 3. nums = [3,7,21]
Example 2:

Input: nums = [5,2,6,2]
Output: false
Explanation: It is impossible to sort the array because 5 cannot be swapped with any other element.
Example 3:

Input: nums = [10,5,9,3,15]
Output: true
We can sort [10,5,9,3,15] by performing the following operations:
- Swap 10 and 15 because gcd(10,15) = 5. nums = [15,5,9,3,10]
- Swap 15 and 3 because gcd(15,3) = 3. nums = [3,5,9,15,10]
- Swap 10 and 15 because gcd(10,15) = 5. nums = [3,5,9,10,15]
 */
public class GCDSortofanArray {
    public static void main(String[] args) {
        int[] nums = {10,5,9,3,15};
        System.out.println(gcdSort(nums));

    }
    public  static boolean gcdSort(int[] nums) {
        for(int i = 0  ; i<= (nums.length/2 ) ; i++){
            for(int j = nums.length-1 ; j>=( nums.length/2)  ; j-- ) {
                int gcd = GCD(nums[i], nums[j]);
                System.out.println(gcd);
                if (gcd > 1) {
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
                 else if(nums[i] > nums[j] && gcd <= 1) return false;
            }
        }
        for(int i = 0 ;i<nums.length-1 ; i++){
            int min = nums[i];
            if(nums[i+1] <min) return false;
        }

     return true;
    }
    static int GCD(int a , int b){
        if(a==0){
            return b;
        }
        return GCD(b%a , a);
    }

}
