#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll big(ll base,ll pow,ll mod)
{
    if(pow==0)
    {
        return 1;
    }
    int x=big(base,pow/2,mod);
    x=(x*x)%mod;
    if(pow%2==1)
        x=(x*base)%mod;
        return x;

}
int main()
{
    ll b,p,m;
    while(cin>>b>>p>>m)
    {
      cout<<big(b,p,m)<<endl;
    }
}
