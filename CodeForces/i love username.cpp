#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int mx=arr[0],mn=arr[0],c=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>mx)
        {
            mx=arr[i];
            c++;
        }
        else if(arr[i]<mn)
        {
            mn=arr[i];
            c++;
        }
    }
    cout<<c<<endl;
    return 0;
}
