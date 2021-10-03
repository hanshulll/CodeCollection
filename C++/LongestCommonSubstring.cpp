//Longest Common Substring


#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        int dp[n+1][m+1];
        
        int ans = 0;
        
        for(int i=0; i<=n; i++)
            dp[i][0] = 0;
        
        for(int i=0; i<=m; i++)
            dp[0][i] = 0;
            
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = 0;
                    
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};



int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}