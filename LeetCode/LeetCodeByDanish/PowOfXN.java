package LeetCode;
/*
https://leetcode.com/problems/powx-n/
Implement pow(x, n), which calculates x raised to the power n (i.e., xn)

Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

 */
public class PowOfXN {
    public static void main(String[] args) {
        double x = 2.10000;
        int n = 3;
        double ans = myPow(x , n);
        System.out.println(ans);
    }
    public static  double myPow(double x, int n) {
//        double pow = 0;
//        if(x == 0) return 0;
//        if(n==0) return 1;
//         if(n > 0) {
//             double hpow = myPow(x, n / 2);
//              pow = hpow * hpow;
//             if (n % x != 0) {
//                 pow *= x;
//             }
//             return pow;
//         }
//         double hpow = myPow(x , (n/2));
//         pow = 1/(hpow*hpow);
//        if (n % x != 0) {
//            pow *= x;
//        }
//        pow = Math.round(pow*100D)/100D;
//        return pow;

        double temp;
        if( n == 0)
            return 1;
        temp = myPow(x, n/2);

        if (n%2 == 0)
            return temp*temp;
        else
        {
            if(n > 0)
                return x * temp * temp;
            else
                return (temp * temp) / x;
        }
    }
}
