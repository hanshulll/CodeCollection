class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.length();
        int m = b.length();
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1));
        
        // making LCS table
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=1 ; j<=m ; j++)
            {
                if(a[i-1] == b[j-1])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
            }
        }
        
        int i = n , j = m , c = dp[n][m];
        string s , ans;
        
        // now we need to backtrack from last cell to find our LCS
        while(i and j)
        {
            if(a[i-1] == b[j-1])
                s+=a[i-1] , i-- , j--;
            else if(dp[i-1][j] > dp[i][j-1]){
                s.push_back(a[i-1]);
                i--;
            }
            else
            {
                s.push_back(b[j-1]);
                j--;
            }
            
        }
        while(i>0)
        {
            s.push_back(a[i-1]);
            i--;
        }
        while(j>0)
        {
            s.push_back(b[j-1]);
            j--;
        }
        reverse(s.begin() , s.end());  
        return s;
    }
};
