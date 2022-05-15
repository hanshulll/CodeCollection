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
ll tt(ll n ,ll k)
{
	ll res=1;
	for(ll i=1i<=k;i++)
	{
		res=res*(n-k+i)/i;
	}
	return (ll)res;
}
int main()
{
    FastRead

    ll n,m,t,ans=0;
    cin>>n>>m>>t;
    for(ll i=4;i<=n;i++)
    {
    	if(i<t && t-i<=m)
    	{
    		ans+=
    	}
    }

	return 0;
}
