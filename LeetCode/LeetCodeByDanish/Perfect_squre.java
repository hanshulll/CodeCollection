package LeetCode;

import java.util.Scanner;

/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.
Follow up: Do not use any built-in library function such as sqrt.
Example 1:
Input: num = 16
Output: true
Example 2:
Input: num = 14
Output: false
 */
public class Perfect_squre {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        System.out.println(isPerfectSquare(n));
    }

    public static boolean isPerfectSquare(int num) {
        long s = 1 ;
        long e = num;
        while(e >=s){
            long mid = s + (e-s)/2;
            if(mid*mid == num) return true;
            else if(mid*mid > num){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return false;

    }
}
