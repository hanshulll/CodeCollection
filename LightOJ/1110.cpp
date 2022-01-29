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
#define   N                   105
#define   all(v)              (v.begin(), v.end())
#define   rall(v)             (v.rbegin(), v.rend())
#define   pi                  acos(-1.0)
#define   LCM(LCM_X,LCM_Y)    (LCM_X/__gcd(LCM_X,LCM_Y))*LCM_Y
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int MOD = (int)1e9+7;
const int MAX = 1e6;

ll mini(string a,string b)
{
	ll dp[N][N];
	ll i,j;
	for(i=0;i<=a.length();i++)
    {
        for(j=0;j<=b.length();j++)
        {
            if(i==0 && j==0)
            {
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            {
                dp[i][j]=(dp[i-1][j-1])+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return a.length()-dp[a.length()][b.length()];
}
int main()
{
    FastRead
    string s;
    cin>>s;
    ll i,len=s.size();
    string s1;
    for(i=0;i<len;i++)
    {
        if(s[i]==0)
        {
            s1+=isuppe
        }

    }

    return 0;
}
