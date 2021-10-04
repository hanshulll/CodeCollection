//Form a palindrome
//Minimum number of insertion to make a string palindrome
//GFG ACCEPTED

#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int countMin(string str)
    {
        //using LCS
        int n = str.size();
        
        string rev = str;
        
        reverse(rev.begin(), rev.end());
        
        int dp[n+1][n+1];

        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if(str[i-1] == rev[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return n - dp[n][n];
    }
};


int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}