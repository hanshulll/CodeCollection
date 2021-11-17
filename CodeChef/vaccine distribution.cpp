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
ll cill(ll a,ll b)
{
    if(a%b==0)
        return a/b;
    return a/b+1;
}
int main()
{
    FastRead

    int d1,v1,d2,v2,p,i;
    cin>>d1>>v1>>d2>>v2>>p;
    ll cnet=0,sum=0,temp=0,cc=0;
    for(int i=1; p>0; i++)
    {
        if(i>=d1)
        {
            p=p-v1;
        }
        if(i>=d2)
        {
            p=p-v2;
        }
        cc++;
    }
    cout<<cc<<endl;
    return 0;
}
