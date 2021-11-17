#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,cnet=0,i;
        cin>>n;
        int arr[n+2];
        for(i=0;i<n;i++)cin>>arr[i];
        sort(arr,arr+n);
        /*for(i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        */
        for(i=1;i<n;i++)
        {
            if(arr[i]-arr[i-1]<=1)
            {
                cnet++;
            }
        }
        if(n-cnet==1)cout<<"YES\n";
        else cout<<"NO\n";

    }

    return 0;
}
