#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    ll t;
    cin>>t;
    read:
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n+2];
        for(int i=1;i<=n;i++)cin>>arr[i];
        for(int i=2;i<=n-1;i++)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                cout<<"YES\n";
                cout<<i-1<<" "<<i<<" "<<i+1<<endl;
                goto read;
            }
        }
        cout<<"NO\n";
    }

    return 0;
}
