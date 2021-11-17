#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,s,z[100],cnet=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        for(int i=0; i<n; i++)
        {
            cin>>z[i];
        }
        for(int i=0;i<n;i++)
        {
            if(z[i]+z[i+2]<10)
            {
                cnet++;
            }
        }
        if(cnet>0)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
