//Plus one : https://leetcode.com/problems/plus-one/
#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &digit)
{

    int carry = 1;

    for (int i = digit.size() - 1; i >= 0; i--)
    {
        int k = digit[i] + carry;
        digit[i] = k % 10;
        carry = k / 10;
    }
    if (digit[0] == 0)
    {
        digit.insert(digit.begin(), 1);
    }

    return digit;
}

int main()
{
    int n;
    cin >> n;

    vector<int> digit(n);

    for (int i = 0; i < n; i++)
    {
        cin >> digit[i];
    }

    vector<int>ans;

    ans = plusOne(digit);

    for(auto it:ans)
    {
        cout<<it<<" ";
    }
}
