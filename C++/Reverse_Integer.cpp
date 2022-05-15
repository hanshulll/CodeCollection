//Reverse Integer : https://leetcode.com/problems/reverse-integer/
#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{

    long long res = 0;
    int flag = 0;

    if (x < 0)
    {
        flag = 1;
        x = abs(x);
    }

    while (x > 0 && res <= INT_MAX)
    {
        res += x % 10;
        x /= 10;

        if (x == 0)
        {
            break;
        }
        res *= 10;
    }

    if (res > INT_MAX)
    {
        return 0;
    }

    else if (flag == 1)
    {
        res = -res;
    }
    return res;
}

int main()
{

    int n;
    cin>>n;
    cout<<reverse(n);
}
