#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int m;
    cin>>m;
    int brr[m];
    for(int i=0;i<m;i++)cin>>brr[i];
    int cnet=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(arr[j]==brr[i])
                cnet++;
        }
    }
    cout<<cnet<<endl;

    return 0;
}
