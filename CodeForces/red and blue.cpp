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
		ll n,sum=0,mx1=0,mx=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			ll x;
			cin>>x;
			sum+=x;
			mx=max(mx,sum);
		}
		sum=0;
		ll m;
		cin>>m;
		for(int i=0;i<m;i++)
		{
			ll y;
			cin>>y;
			sum+=y;
			mx1=max(mx1,sum);
		}
		cout<<mx+mx1<<endl;

	}

	return 0;
}
