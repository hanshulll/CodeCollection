#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    ll t,x=0;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        x=n*2;
        if(x>m)cout<<"-1 -1\n";
        else
            cout<<n<<" "<<m<<endl;
    }
    return 0;
}
