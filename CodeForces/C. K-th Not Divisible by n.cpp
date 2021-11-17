#include<bits/stdc++.h>
#define ll long long
#define mx 1000000000
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k,i;
        cin>>n>>k;
        ll need=((k-1)/(n-1));
        cout<<(need+=k)<<"\n";
    }
    return 0;
}
