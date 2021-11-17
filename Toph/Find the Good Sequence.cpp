#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[1000000];
    int brr[1000000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    brr[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i+1]-arr[i]>=2)
        {
            brr[i]=brr[i+1]+1;
        }
        else
        {
            brr[i]=1;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(brr[i]==1)cout<<"0\n";
        else
        {
            cout<<brr[i]<<endl;
        }
    }
    return 0;
}
