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
int32_t main()
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
		ll n,q;
		cin>>n>>q;
		string s;
		cin>>s;
		while(q--)
		{
			ll l,r,f=0;
			cin>>l>>r;
			string x=s[l-1],y=[r-1];
			for(int i=0;i<l-1;i++)
			{
				if(s[i]==x)
				{
					f=1;
					break;
				}
			}
			for(int i=r;i<n;i++)
			{
				if(s[i]==y)
				{
					f=1;
					break;
				}
			}
			if(f)cout<<"YES\n";
			else cout<<"NO\n";
		}

	}

	return 0;
}
