#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,arr[1000];
    cin>>n>>m;
    for(int i=0;i<m;i++)cin>>arr[i];
    int mn=1234567;
    sort(arr,arr+m);
    /*for(int i=0;i<m;i++)
    {
        cout<<arr[i]<<" ";
    }
    */
    for(int i=n;i<=m;i++)
    {
        mn=min(mn,abs(arr[i-n]-arr[i-1]));
    }
    cout<<mn<<endl;

    return 0;
}
