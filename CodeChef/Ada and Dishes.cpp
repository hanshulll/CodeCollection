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
		int n;
		cin>>n;
		vector<int>vc;
		for(int i=0;i<n;i++)
		{
			ll p;
			cin>>p;
			vc.push_back(p);
		}
		sort(vc.begin(),vc.end());
		int j=n-1,a=0,b=0;
		while(j>=0)
		{
			if(a<b)
			{
				a+=vc[j];
			}
			else
			{
				b+=vc[j];
			}
			j--;
		}
		cout<<max(a,b)<<endl;
	}

	return 0;
}
	