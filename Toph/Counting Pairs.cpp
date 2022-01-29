#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,k=1;
    cin>>t;
    while(t--)
    {
        long long int n,i,cnet=0;
        cin>>n;
        long long int arr[n];
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]%5==0)
            {
                cnet++;
            }
        }
        cout<<"Case "<<k<<": "<<cnet*2<<endl;
        k++;
    }
    return 0;
}
