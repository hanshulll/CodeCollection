#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,i;
        cin>>n>>m;
        ll arr[m];
        for(i=0; i<m; i++)
            cin>>arr[i];
        sort(arr,arr+m, greater<int>());
        ll sum=0;
        for(i=0; i<min(n,m); i++)
        {
            sum+=arr[i];
        }
        cout<<sum<<endl;

    }
    return 0;
}
