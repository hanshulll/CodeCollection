#include<bits/stdc++.h>
using namespace std;
                 //Welcome To Hridoy's Code
#define   ll                  long long
#define   ull                 unsigned long long
#define   mod                 100000007
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
ll coin[55];
ll time[55];
ll n,k;
ll dp[50][1000];
ll change(ll a, ll b)
{
	if(b==k)return 1;
	else if(a==n)return 0;
	else if(dp[a][b]!=-1)return dp[a][b];
	else
	{
		ll res=0;
		for(ll i=0;i<=coin[a];i++)
		{
			if(time[a]*i+b<=k)
			{
				res=(res+change(a+1,b+time[a]*i))%mod;
			}
		}
		return dp[a][b]=r%mod;
	}

}
int main()
{
    FastRead
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k;
		cin>>n>>k;
		for(ll i=0;i<n;i++)cin>>coin[i];
		for(ll i=0;i<n;i++)cin>>time[i];
		memset(dp,-1,sizeof(dp));
		cout<<change(0,0)<<endl;

	}

	return 0;
}
