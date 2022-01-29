//Rod Cutting
//DP

#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:

    //a problem of unbounded knapsack
    int cutRod(int price[], int n) 
    {
        int dp[n+1][n+1];
        
        for(int i=0; i<=n; i++)
            dp[i][0] = 0;
            
        for(int i=0; i<=n; i++)
            dp[0][i] = 0;
            
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(j >= i)
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-i]+price[i-1]);
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        
        return dp[n][n];
    }
};




int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}