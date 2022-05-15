#include<bits/stdc++.h>
using namespace std;
                 //Welcome To Hridoy's Code
#define   ll                  long long
#define   mod                 100000007
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

ll coinchange(ll n)
{
	ll i,j;
	vector<ll>dp(n+1,0);
	dp[0]=1;
	vector<ll>coin;
	for(i=1;i<=21;i++)
	{
		coin.pb(i*i*i);
	}
	for(i=0;i<22;i++)
	{
		for(j=coin[i];j<10000;j++)
		{
			{
				dp[j]+=dp[j-coin[i]];
			}
			//else break;

		}
	}
	return dp[n];
}
int main()
{
    FastRead
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	ll n;
	while(cin>>n)
	{
		cout<<coinchange(n)<<endl;
	}

	return 0;
}
