package LeetCode;

import java.lang.reflect.Array;
import java.util.Arrays;

/*
https://leetcode.com/problems/plus-one/
You are given a large integer represented as an integer array digits,
where each digits[i] is the ith digit of the integer.
The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.
Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [0]
Output: [1]
Explanation: The array represents the integer 0.
Incrementing by one gives 0 + 1 = 1.
Thus, the result should be [1].

Example 4:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
 */
public class PlusOne {
    public static void main(String[] args) {
        int[] arr = {9,9,9};
        int[] ans = plusOne(arr);
        System.out.println(Arrays.toString(ans));

    }

    public static int[] plusOne(int[] digits) {
       if(digits[digits.length-1] < 9){
           digits[digits.length-1] =  digits[digits.length-1]+1;
           return digits;
       }
        int temp[] = new int[digits.length+1];

        int carry = 0 ;
        for(int i = digits.length-1 ; i>=0 ; i--) {

            if(digits[i] == 9) {
                carry = 1 ;
                temp[i+1] = 0 ;
                digits[i] = 0;
            }
            else {
                temp[i+1] = digits[i] + carry;
                digits[i] = digits[i] + carry;
                carry = 0 ;
                break;

            }
        }
        temp[0] = carry ;
        if(temp[0] == 0){
            return digits;
        }
        return temp;

    }
}
