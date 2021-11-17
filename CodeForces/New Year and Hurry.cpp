#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,cnet=0,mul=5,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        ans+=mul*i;
        if(ans+k>240)
        {
            break;
        }
        cnet++;
    }
    cout<<cnet<<endl;
    return 0;
}
