package LeetCode;

import java.util.Scanner;

/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x
 */
public class PowerOfTwo {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        System.out.println(isPowerOfTwo(n));

    }
    public static boolean isPowerOfTwo(int n) {
        if(n<=0) return false;
        if(n==2 || n==1) {
            return true;
        }
        if(n%2==0) {
            return isPowerOfTwo(n/2); //keep on dividing by 2
        }

        return false;
    }
}
