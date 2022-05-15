#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,l,i,rez=0,lel=0;
    cin>>n>>l;
    ll arr[n];
    for(i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    rez=2*max(arr[0],l-arr[n-1]);
    //cout<<rez<<endl;
    for(i=0;i<n-1;i++)
    {
        rez=max(rez,arr[i+1]-arr[i]);
    }

    printf("%.10f\n",rez/2.);

    return 0;
}
