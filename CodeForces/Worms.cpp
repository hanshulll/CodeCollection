#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>vc;
int main()
{
    ll n,i,sum=0;
    cin>>n;
    ll arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        vc.push_back(sum);
    }
    ll q;
    cin>>q;
    for(i=0;i<q;i++)
    {
        ll t;
        cin>>t;
        if(t<=vc[0])
        {
            cout<<"1\n";
            continue;
        }
        else
        {
            cout<<lower_bound(vc.begin(),vc.end(),t)-vc.begin()+1<<"\n";
        }

    }
    return 0;

}
