#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    ll n,k;
    cin>>n>>k;
    ll arr[n+2];
    for(int i=0;i<n;i++)cin>>arr[i];
    ll cnet=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=arr[i+1] && arr[i]>=k)
        {
            cnet++;
        }
    }
    cout<<cnet<<endl;

    return 0;
}
