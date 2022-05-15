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
const int N = 109;
string dp[N][N];

string mini(string a,string b)
{
	if(a.size()!=b.size())
	{
		if(a.size()>b.size())return b;
		else return a;
	}
	return mini(a,b);
}
int main()
{
	int t,cnet=0;
	cin>>t;
	while(t--)
	{
		string s,ss;
		cin>>s>>ss;
		ll i,j,len=s.size(),len1=ss.size();

		for(i=1;i<=len;i++)
		{
			for(j=1;j<=len1;j++)
			{
				dp[i][j]=mini(dp[i-1][j],dp[i][j-1]);

				if(s[i-1]==ss[j-1])
				{
					dp[i][j]=mini(dp[i][j],dp[i-1][j-1]+s[i-1]);
				}
			}
		}
		string ans=dp[s.size()][ss.size()];
		if(ans=="")cout<<"Case "++cnet<<": "<<":(\n";
		else cout<<"Case "++cnet<<": "<<ans<<endl;
	}

   

	return 0;
}
