
#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0)
#define FOR(i, a, b) for(int i = a;i < b; i++)
#define rev(i, a, b) for(int i = a;i > b; i--)
#define si(a)   scanf("%d", &a)
#define pi(a)   printf("%d\n", a)
typedef long long ll;								//W
#define pb push_back								//E
#define ff first										//A
#define ss second									//K
#define MOD (ll)1000000007
#define M_PI 3.14159265358979323846
#define N 1000005
#define EPS 1e-12
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
using namespace std;

vector<ll> g[N];
bool f[N]={0};
bool curr[N]={0};
//bool sold[N]={0};


bool solve(ll a, ll b)
{
	if(f[a])
		return 0;

	queue<pair<ll, ll> > q;
	q.push({a, b});
	f[a]=1;
	curr[a] = 1;
	ll v, h;

	while(!q.empty())
	{

		v = q.front().ff;
		h = q.front().ss;
		q.pop();
		if(h>0)
		{
			for(auto w:g[v])
			{
				if(!curr[w])
				{
					if(f[w])
						return 0;

					curr[w]=1;
					f[w]=1;
					q.push({w, h-1});
				}

			}
		}
	}
	return 1;
}

int main()
{
	fio;
	ll t, n, r, m;
	cin>>t;

	while(t--)
	{
		pair<ll, ll> p;
		cin>>n>>r>>m;
		while(r--)
		{
			ll x,y;
			cin>>x>>y;
			g[y].pb(x);
			g[x].pb(y);
		}

		vector<pair<ll, ll> > as;
		while(m--)
		{
			ll x,y;
			cin>>x>>y;
			//sold[x] = 1;
			p = {x, y};
			as.pb(p);
		}

		bool fl;
		for(auto i:as)
		{
			fl = solve(i.ff, i.ss);
			if(!fl)
				{cout<<"No\n"; break;}
		}
		if(fl)
		{
			for(ll i=1;i<=n;i++)
			if(!f[i])
			{
				fl=0;
				cout<<"No\n";
				break;
			}
		}
		if(fl) cout<<"Yes\n";

		//clear
		for(ll i=0;i<=n;i++)
			g[i].clear();
		as.clear();
		memset(f, 0, sizeof(f));
		//memset(sold, 0, sizeof(sold));
	}

	return 0;
}
