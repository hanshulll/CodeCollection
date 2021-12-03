#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,k,i,cnet=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        if(x%k==0)
        {
            cnet++;
        }
    }
    cout<<cnet<<endl;

    return 0;
}
