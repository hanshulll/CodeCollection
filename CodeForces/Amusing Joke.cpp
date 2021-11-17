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
    string s1,s2,s3,s4,c,d;
    cin>>s1>>s2>>s3;
    s4=s1+s2;
    sort(s4.begin(),s4.end());
    sort(s3.begin(),s3.end());
    if(s3==s4)
    {
    	cout<<"YES\n";
    }
    else
    {
    	cout<<"NO\n";
    }

	return 0;
}
