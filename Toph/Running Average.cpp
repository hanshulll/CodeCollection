#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i=1;
    cin>>n;
    int arr[n+2];
    float s=0,aveg;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        s+=arr[i];
        aveg=s/i;
        cout<<aveg<<endl;
    }

    return 0;
}
