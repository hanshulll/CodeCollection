#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    ll n,k,i;
    vector<ll>v;
    cin>>n>>k;
    ll arr[n+2];
    for(i=0;i<n;i++)cin>>arr[i];
    for(i=0;i<k;i++)
    {
        if(arr[i]!=arr[i+1])
        {
            v.push_back(arr[i]);
        }
    }
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}
