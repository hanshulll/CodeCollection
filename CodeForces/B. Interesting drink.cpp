#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll arr[100000];
int main()
{
    ll n,i;
    cin>>n;
    for(i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    ll q;
    cin>>q;
    while(q--)
    {
        ll item;
        cin>>item;
        ll start=0,End=n-1,mid;
        while(start<=End)
        {
            mid=(start+End)/2;
            if(arr[mid]<=item)
            {
                start=mid+1;
            }
            else
            {
                End=mid-1;
            }

        }
        cout<<start<<"\n";
    }

    return 0;

}
