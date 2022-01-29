#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        if(a*2>b)cout<<b<<endl;
        else cout<<"-1"<<endl;
    }

    return 0;
}
