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
ll wt[12345],val[12345];
ll kp(ll w, ll wt[], ll val[], ll n)
{
    ll i,j;
    ll k[n+1][w+1];

    for(i = 0; i <= n; i++)
    {
        for( j = 0; j <= w; j++)
        {
            if(i == 0 || j == 0)
                k[i][j] = 0;
            else if(wt[i-1]<=j)
                k[i][j] = max(val[i-1]+k[i-1][j-wt[i-1]], k[i-1][j]);
            else
                k[i][j] = k[i-1][j];
        }
    }
    return k[n][w];
}
int main()
{
    FastRead

    ll t;
    cin>>t;
    while(t--)
    {
        memset(wt,0,sizeof(wt));
        memset(val,0,sizeof(val));
        ll n,i;
        cin>>n;
        for(i=0; i<n; i++)
            cin>>val[i]>>wt[i];
        ll pep,ans=0;
        cin>>pep;
        for(i=0; i<pep; i++)
        {
            ll m;
            cin>>m;
            ans+=kp(m,wt,val,n);
        }
        cout<<ans<<endl;
    }
    return 0;
}
