package LeetCode;
/*
https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
Given an integer number n, return the difference between the product of its digits and the sum of its digits.

Example 1:

Input: n = 234
Output: 15
Explanation:
Product of digits = 2 * 3 * 4 = 24
Sum of digits = 2 + 3 + 4 = 9
Result = 24 - 9 = 15
Example 2:

Input: n = 4421
Output: 21
Explanation:
Product of digits = 4 * 4 * 2 * 1 = 32
Sum of digits = 4 + 4 + 2 + 1 = 11
Result = 32 - 11 = 21
 */
public class Diff_Sum_Mul {
    public static void main(String[] args) {
        int n = 4421;
        int diff = subtractProductAndSum(n);
        System.out.println(diff);

    }
    public static int subtractProductAndSum(int n) {
        int sum=0;
        int prod =1;
        while (n>0){
            sum+=n%10;
            prod*=n%10;
            n/=10;
        }
        return prod-sum;

    }
}
