#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t,i;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+2];
        for(i=0;i<n;i++)cin>>arr[i];
        cout<<*max_element(arr,arr+n)-*min_element(arr,arr+n)<<endl;
    }

    return 0;
}
