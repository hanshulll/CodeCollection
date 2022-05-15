//#define sort(nums) sort(nums.begin(),nums.end())
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
using ll= long long int;
void jets(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    jets();
    int n,sum;
    cin>>n>>sum;
    std::vector<ll> vec(n);
    for(int i=0;i<n;i++)
        cin>>vec[i];
    int dp[sum+1]={0};
    dp[0]=1;
    for(int i=1;i<=sum;i++){
        for(int coin : vec){
            if(coin<=i)
                dp[i]=(dp[i]+dp[i-coin])%mod;
        }
    }
    cout<<dp[sum];
    return 0;
}