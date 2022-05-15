package LeetCode;
/*
https://leetcode.com/problems/happy-number/
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay),
or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:
Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Example 2:
Input: n = 2
Output: false
 */
public class HappyNumber {
    public static void main(String[] args) {

    }


    private int findSquare(int number){
        int ans = 0;
        while(number >0){
            int rem = number%10;
            ans += rem*rem;
            number /=10;
        }
        return ans;
    }

    public boolean isHappy(int n) {
        int slow = n;
        int fast = n;

        do{
            slow = findSquare(slow);
            fast = findSquare(findSquare(fast));

        }while(slow != fast);

        if(slow == 1) return true;
        return  false;

    }
}
