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
    string s;
    cin>>s;
    ll cnet=0,dp[100001]={0};
    ll len=s.size();
    for(int i=0;i<len;i++)
    {
    	if(s[i]==s[i+1])
    	{
    		cnet++;
    	}
    	dp[i++]=cnet;
    }
    ll q;
    cin>>q;
    while(q--)
    {
    	ll a,b;
    	cin>>a>>b;
    	cout<<dp[b-1]-dp[a-1]<<endl;
    }

	return 0;
}
