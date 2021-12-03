#include<bits/stdc++.h>
#define ll long long
#define Mx 1000000
#define endl "\n"
using namespace std;

void binary(ll arr[],ll item,ll m)
{
    ll start=0,mid,end=m-1,i,j,loc=-1;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]<item)
        {
            cout<<arr[mid]<<" ";
            start=mid+1;
        }
        if(arr[mid]>item)
        {
            cout<<arr[mid]<<" ";
            end=mid-1;
        }
        else
        {
            cout<<"X"<<" ";
            break;
        }
    }
    cout<<"\n";

}
int main()
{
    ll n,i;
    cin>>n;
    ll arr[n];
    for(i=0;i<n;i++)cin>>arr[i];
    ll start,end,mid,q,tas;
    cin>>q;
    while(q--)
    {
        ll tas;
        cin>>tas;
        binary(arr,tas,n);
    }

}
