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
	ll cs[100010];
	ll n,m;;
	cin>>n>>m;
	vector<pair<ll,ll> >v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first>>v[i].second;
		
	}
	sort(v.begin(),v.end());
	ll maxi=0,sum=0,beg=0,end=0;
	while(end<n)
	{
		while(end<n && v[end].first-v[beg].first+1<=m)
		{
			sum+=v[end].second;
			end++;
		}
		maxi=max(maxi,sum);
		sum-=v[beg].second;
		beg++;
	}

	return 0;
}
