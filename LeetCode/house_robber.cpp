//Problem:https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
using namespace std;
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 3, -1);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int i = 1; i < n; i++)
    {
        dp[i + 1] = max(dp[i - 1] + nums[i], dp[i]);
    }
    return dp[n];
}

int main()
{
    int n;
    cout << "Enter the Number of house in row\n";
    cin >> n;
    cout << "Enter the amount of money in array\n";
    vector<int> amt_in_house(n);
    for (int i = 0; i < n; i++)
    {
        cin >> amt_in_house[i];
    }
    //print the maximum amount can
    //be robbed with constraints
    int answer = rob(amt_in_house);
}