#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll solve()
{

}
int main()
{
    ll t,i;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        ll n,k;
        cin>>n>>k;
        ll ans=1,dig=k;
        while((k%n)!=0)
        {
            k=(k*10+dig)%n;
            ans++;
        }
        cout<<"Case "<<i<<": ";
        cout<<ans<<"\n";

    }
    return 0;
}
