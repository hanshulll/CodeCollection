#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[100000];
int main()
{
    ll n,q,i;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    while(q--)
    {
        ll l,r,tot=0,cnet=0;
        cin>>l>>r;
        tot=(r-l)+1;
        cnet=arr[r]-arr[l-1];
        tot-=cnet;
        cout<<(tot>cnet? "0":"1")<<"\n";
    }
    return 0;
}
