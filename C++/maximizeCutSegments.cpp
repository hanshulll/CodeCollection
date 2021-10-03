#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = (int)1e9 + 7;

// int maximizeTheCuts(int n, int x, int y, int z)
// {
//     //Your code here
//     int dp[n + 1] = {0};
//     for(int i = 0 ; i <= n ; i++){
//         if(i == 0){
//             dp[i] = 0;
//         }
//         else{
//             if(i - x >= 0){
//                 dp[i] = max(dp[i], dp[i - x] + 1);
//             }
//             if(i - y >= 0){
//                 dp[i] = max(dp[i], dp[i - y] + 1);
//             }
//             if(i - z >= 0){
//                 dp[i] = max(dp[i], dp[i - z] + 1);
//             }
//         }
//     }

//     for(int i = 0 ; i <= n ; i++){
//         cout<<i<<" "<<dp[i]<<"\n";
//     }
    
//     return dp[n];
// }

int memo[10001];

int solve(int n, int x, int y, int z){
    if(n < 0){
        return -10002;
    }
    if(n == 0){
        return 0;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    int ans = 0;
    int a = solve(n - x, x, y, z) + 1;
    int b = solve(n - y, x, y, z) + 1;
    int c = solve(n - z, x, y, z) + 1;
    
    ans = max(a, max(b, c));
    // if(ans < 0){
    //     ans = 0;
    // }
    memo[n] = ans;
    
    return ans;
}
//Function to find the maximum number of cuts.
int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    memset(memo, -1, sizeof(memo));
    int ans = solve(n, x, y, z);
    if(ans < 0){
        return 0;
    }
    else {
        return ans;
    }
    // int dp[n + 1] = {0};
    // for(int i = 0 ; i <= n ; i++){
    //     if(i == 0){
    //         dp[i] = 0;
    //     }
    //     else{
    //         if(i - x >= 0){
    //             dp[i] = max(dp[i], dp[i - x] + 1);
    //         }
    //         if(i - y >= 0){
    //             dp[i] = max(dp[i], dp[i - y] + 1);
    //         }
    //         if(i - z >= 0){
    //             dp[i] = max(dp[i], dp[i - z] + 1);
    //         }
    //     }
    // }
    
    // return dp[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cout<<maximizeTheCuts(7, 5, 5, 2)<<"\n";
    cout<<maximizeTheCuts(9999, 94, 20, 244)<<"\n";
    cout<<maximizeTheCuts(5, 5, 3, 2)<<"\n";
    cout<<maximizeTheCuts(4, 2, 1, 1)<<"\n";

    return 0;
}
