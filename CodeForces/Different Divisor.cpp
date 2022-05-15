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

char prime[MAX];

void sieve()
{
    ll i,j;
    prime[0]=1;
    for(i=2;i<=MAX;i+=2)prime[i]=1;
    for(i=3;i<=MAX;i+=3)prime[i]=1;
}
int main()
{
	sieve();
    FastRead
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
	
	int t;
	cin>>t;
	while(t--)
	{
		int d;
		cin>>n;
		vector<int>vc;
		for(int i=1;i<=4;i++)
		{
			vc.pb(i+d);
			if(i==4)
			{
				cout<<vc[0]*vc[1]<<endl;
				return 0;
			}
		}



	}

	return 0;
}
