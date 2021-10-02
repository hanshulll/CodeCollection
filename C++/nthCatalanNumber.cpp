#include <iostream>

using namespace std;

int findCatalan(int n)
{
    int ans[n + 1] = {0};
    for (int i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            // C(0)th = 1
            ans[i] = 1;
        }
        else
        {
            // C (n + 1)th = summation from i = 0 to n of C(i)th * C(n - i)th and n >= 0
            for (int j = 0; j < i; j++)
            {
                ans[i] += ans[j] * ans[i - 1 - j];
            }
        }
    }

    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << findCatalan(n);
}