#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,k=1;
    cin>>t;
    while(t--)
    {
        long long int n,a=0;
        cin>>n;
        long long int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]>0)
            {
                a+=arr[i];
            }
        }
        cout<<"Case "<<k<<": "<<a<<endl;
        k++;
    }
    return 0;
}
