#include <bits/stdc++.h>
using namespace std;

#define f(i, a, b) for (int i = a; i < b; i++)
#define vi vector<int>

int lcs(string s1, string s2, vector<vector<int>> &dp)
{
    int n = s1.size() + 1, m = s2.size() + 1;
    f(i, 1, n)
    {
        f(j, 1, m)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n - 1][m - 1];
}

int main()
{

    string s1, s2;
    cout << "Enter the Strings: ";
    cin >> s1 >> s2;
    int n = s1.size() + 1, m = s2.size() + 1;
    vector<vector<int>> dp(n, vector<int>(m, 0));
    cout << "\nLength of the Longest Common SubSequence is  " << lcs(s1, s2, dp) << endl;
    return 0;
}