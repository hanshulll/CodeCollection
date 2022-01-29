/* 
Given an integer N, find the square of N without using the * (multiplication) operator
or the pow function.
Example:
Input:
5
Output:
25
Explanation: 5 * 5 = 25
*/

import java.util.*;

public class SquareWithoutOperator {
    static int square(int n) {
        if (n == 0)
            return 0; // Square of zero is equal to zero
        if (n < 0)
            n = -n; // Handling negative numbers
        int t = n >> 1; // Equivalent to n / 2
        if (n % 2 == 0)
            return (square(t) << 2); // Equivalent to square(t) * 4;
        return ((square(t) << 2) + (t << 2) + 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        System.out.println(square(a));
        sc.close();
    }
}