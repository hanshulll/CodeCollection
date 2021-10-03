/* -------------------------------------------------------------------------- */
/*                 Triangle With Angle Problem Code: ANGTRICH                 */
/* -------------------------------------------------------------------------- */

/**You're given the three angles a, b, and c respectively. 
 * Now check if these three angles can form a valid triangle with an area greater than 0 or not. 
 * Print "YES"(without quotes) if it can form a valid triangle with an area greater than 0, otherwise print "NO" (without quotes).
*/

/*
Input:
    First-line will contain three numbers a, b, and c separated by space.

Output:
    Print "YES"(without quotes) if these sides can form a valid triangle, otherwise print "NO" (without quotes).

Constraints
    0≤a,b,c≤180

Sample Input 1:
    20 40 120

Sample Output 1:
    YES

Sample Input 2:
    100 18 42

Sample Output 2:
    NO

EXPLANATION:
    In the first example, angles set (20, 40, 120) can form a triangle with an area greater than 0.
    In the second example, angles set (100, 18, 42) will never form a valid triangle.
*/

/* ---------------------------------- Code ---------------------------------- */

// #include <iostream>
// using namespace std;

// int main()
// {
//     int a, b, c;
//     cin >> a >> b >> c;
//     if (0<= a <= 180 && 0<= b <= 180 && 0<= c <= 180)
//     {
//         if ((a + b + c) == 180)
//             cout << "YES";
//         else
//             cout << "NO";
//     }
//     else
//         cout << "NO";
//     return 0;
// }

/* ---------------------------------- code ---------------------------------- */

// #include <iostream>
// using namespace std;
// int main()
// {
//     int a, b, c;
//     cin >> a >> b >> c;
//     cout << (a + b + c == 180 && a && b && c ? "YES" : "NO");
//     return 0;
// }

/* ---------------------------------- code ---------------------------------- */

// #include <iostream>
// using namespace std;

// int main()
// {
//     int a, b, c;
//     cin >> a >> b >> c;
//     if ((a > 0 && a < 180) && (b > 0 && b < 180) && (c > 0 && c < 180))
//         if ((a + b + c) == 180)
//             cout << "YES";
//         else
//             cout << "NO";
//     else
//         cout << "NO";
//     return 0;
// }

/* ---------------------------------- code ---------------------------------- */

// #include <iostream>
// using namespace std;
// int main()
// {
//     int a, b, c;
//     cin >> a >> b >> c;
//     cout << (((a > 0 && a < 180) && (b > 0 && b < 180) && (c > 0 && c < 180)) ? (((a + b + c) == 180) ? "YES" : "NO") : "NO");
//     return 0;
// }

/* -------------------------------- Temp Code ------------------------------- */

// #include <iostream>
// using namespace std;
// int main()
// {
//     int a, b, c;
//     cin >> a >> b >> c;
//     cout << (a + b + c == 180 && a > 0 && b > 0 && c > 0 ? "YES" : "NO");
//     return 0;
// }

/* ----------------------------- Study Material ----------------------------- */

/* -------------------------------------------------------------------------- */
/*                http://www.dnawebagency.com/ternary-operator/               */
/* -------------------------------------------------------------------------- */