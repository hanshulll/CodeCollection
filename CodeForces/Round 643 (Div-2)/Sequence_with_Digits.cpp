#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define imx INT_MAX
#define imn INT_MIN
#define llmx LLONG_MAX
#define llmn LLONG_MIN
#define INF         100000000000000000
#define PI          3.1415926535897932384626433832795l



#define fi first
#define se second
#define pb push_back
#define f_s(a) sort(a.begin(), a.end())
#define b_s(a) sort(a.rbegin(), a.rend())
#define p(a) cout<<a<<"\n"


// ll mod = 1000000007;
// #define l(i, )
// #define rl(i, a, b) for(int i = a; i < b; i++)






// struct mycomp {
//     bool operator() (const pair<int,int> &a, const pair<int,int> &b) const{
//         if (a.second-a.first != b.second-b.first)
//         return (a.second-a.first > b.second-b.first);
//         return a.first < b.first;
//     }
// };



/////////////////////GCD//////////////////////
ll gcd(ll a, ll b)
{
	if(b==0) return a;
	return gcd(b, a%b);
}


ll extended_gcd(ll a, ll b, ll& x, ll& y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	ll x1, y1;
	ll d = extended_gcd(b, a%b, x1, y1);
	x=y1;
	y=x1-y1*(a/b);
	return d;
}

////////////////////SIEVE OF ERATOSTHENES//////////////////////
vector<int> sieveoferatosthenes(int n)
{
	vector<bool> prime(n+1, true);
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(prime[i])
		{
			for(int j = i*i; j<=n; j+=i)
			{
				prime[j]=false;
			}
		}
	}
	vector<int> all_primes;
	for(int i = 2; i <=n; i++)
	{
		if(prime[i]) all_primes.pb(i);
	}
	return all_primes;
}

////////////////////BINARY EXPONENTIATION///////////////////////
ll bin_exp(ll a, ll b, ll mod)
{
	ll ans = 1;
	while(b)
	{
		if(b%2)
		{
			b--;
			ans = (ans%mod*a%mod)%mod;
		}
		b/=2;
		a = (a%mod*a%mod)%mod;
	}
	return ans;
}

ll mi(ll n)
{
	ll minim = 10;
	while(n)
	{
		// maxim = max(maxim, temp1%10);
		minim = min(minim, n%10);
		n/=10;
	}
	return minim;
}
ll ma(ll n)
{
	ll maxim = -1;
	while(n)
	{
		maxim = max(maxim, n%10);
		// minim = min(minim, temp1%10);
		n/=10;
	}
	return maxim;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif

	int t;
	cin>>t;
	while(t--)
	{
		ll a, k;
		cin>>a>>k;
		ll temp1 = a, temp2 = a;
		ll minim = 100, maxim =-1;
		minim=mi(a);
		maxim=ma(a);
		ll ans = a;
		ll prev = a;
		while(k>1 and minim!=0)
		{
			ans=prev+mi(prev)*ma(prev);
			prev = ans;
			minim=mi(prev);
			maxim=ma(prev);
			k--;
		}
		p(prev);
	}
	
	return 0;
}