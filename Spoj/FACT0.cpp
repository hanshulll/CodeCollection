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
	
	ll n,a,b,l,i;
	while(cin>>n && n!=0)
	{
		if(n<0)
		{
			n*=-1;
		}
		b=0;
		for(i=2;i<=sqrt(n) && n!=1;i++)
		{
			l=0;
			while(n%i==0)
			{
				n=n/i;
				b=i;
				l++;
			}
			if(b==i)cout<<i<<"^"<<l<<" ";
		}
		if(n!=1)cout<<n<<"^1 ";
		if(n==1 && b==0)cout<<"1^1 ";
		cout<<endl;
	}

	return 0;
}
