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
ll arr[1009];
ll brr[1009];
string s[1009];
int main()
{
    FastRead
    ll n,m,i,j,ans=0;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
    	cin>>s[i];
    	for(j=0;j<m;j++)
    	{
    		if(s[i][j]=='*')
    		{
    			arr[i]++;
    			brr[j]++;
    		}
    	}
    }
    for(i=0;i<n;i++)
    {
    	for(j=0;j<m;j++)
    	{
    		if(s[i][j]=='*')
    		{
    			arr[i]++;
    			brr[j]++;
    		}
    	}
    }


	return 0;
}
