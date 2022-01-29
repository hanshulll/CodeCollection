#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = (int)1e9 + 7;

int countFriendsPairings(int n) 
{ 
    // code here
    long long dp[n + 1] = {0};
    for(int i = 0 ; i <= n ; i++){
        if(i == 0){
            dp[i] = 0;
        }
        else if(i == 1){
            dp[i] = 1;
        }
        else if(i == 2){
            dp[i] = 2;
        }
        else{
            dp[i] = (((i - 1) * dp[i - 2]) % 1000000007 + dp[i - 1]) % 1000000007;
        }
    }
    return (int)dp[n];
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cout<<countFriendsPairings(6569)<<"\n";
    
    return 0;
}
