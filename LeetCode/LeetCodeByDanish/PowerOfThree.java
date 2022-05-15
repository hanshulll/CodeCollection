package LeetCode;
/*
https://leetcode.com/problems/power-of-three/
Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3x.

Example 1:
Input: n = 27
Output: true

Example 2:
Input: n = 0
Output: false

 */
public class PowerOfThree {
    public static void main(String[] args) {
        int n = 27;
        System.out.println(isPowerOfThree(n));

    }
    public static boolean isPowerOfThree(int n) {
        // First Method
//        if(n <= 0) return false;
//        if(n== 1 || n == 3) return true;
//        return  n%3 == 0 && isPowerOfThree(n/3);

        // Second Method
//        while(n>=3){
//            if(n%3!=0) return false;
//            n/=3;
//        }
//        return n==1;

        // Third Method
//        if(n<=0) return false;
//        int m = n;
//        if(m%3==0)
//            return isPowerOfThree(m/3);
//        if(m==1) return true;
//        return false;

        //fourth method.
        if(n == 0) return false;
        int flag = 0;
        aa:
        while(n != 1) {
            if(n%3 != 0){
                flag = 1;
                break ;
            }
            n = n/3;
        }
        return flag == 0? true: false;

    }
}
