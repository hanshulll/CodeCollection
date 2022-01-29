#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        set<ll>s;
        for(ll i=0;i<n;i++)
        {
            ll m;
            cin>>m;
            s.insert(m);
        }
        if(s.size()==n)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
