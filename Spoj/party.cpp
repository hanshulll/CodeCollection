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
#define   LCM(LCM_X,LCM_Y)    (LCM_X/__gcd(LCM_X,LCM_Y))*LCM_Y
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int MOD = (int)1e9+7;
const int MAX = 1e6;
int wt[12345],val[12345];
int main()
{
    FastRead
    ll bug,pat;
    while(cin>>bug>>pat)
    {
        if(bug==0 && pat==0)
            break;
        int i,j;
        for(i=0; i<pat; i++)
        {
            cin>>val[i]>>wt[i];
        }
        int dp[bug+1];
        memset(dp,0,sizeof(dp));
        for(i=0; i<pat; i++)
        {
            for(j=bug; j>=wt[i]; j--)
            {
                dp[j]=max(dp[j],val[i]+dp[j-wt[i]]);
            }
        }
        ll money=dp[bug];
        ll fun=0;
        for(i=0;i<bug;i++)
        {
            if(dp[bug]==money)
            {
                fun=i;
            }
        }
        cout<<fun<<" "<<money<<endl;

    }

    return 0;
}

