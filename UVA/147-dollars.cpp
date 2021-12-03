#include<bits/stdc++.h>
using namespace std;
//Welcome To Hridoy's Code
#define   ll                  long long
#define   ull                 unsigned long long
#define   pb                  push_back
#define   em                  emplace_back
#define   ff                  first
#define   ss                  second
#define   endl                "\n"
#define   all(v)              (v.begin(), v.end())
#define   rall(v)             (v.rbegin(), v.rend())
#define   pi                  acos(-1.0)
#define   neg                 1e-6
#define   LCM(LCM_X,LCM_Y)    (LCM_X/__gcd(LCM_X,LCM_Y))*LCM_Y
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int MOD = (int)1e9+7;
const int MAX = 1e6;
ll coins[]= {5,10,20,50,100,200,500,1000,2000,5000,10000};
ll dp[30005];

int main()
{
    FastRead;
    ll i,j;
    dp[0]=1;
    for(i=0;i<11;i++)
    {
        for(j=coins[i];j<=30000;j++)
        {
            dp[j]+=dp[j-coins[i]];
        }
    }
    double n;
    while(~scanf("%lf", &n))
    {
        if(n - 0.00 < neg)
            break;
        ll x = (n * 100 +0.5);
        printf("%6.2f%17lld\n", n, dp[x]);

    }
    return 0;
}
