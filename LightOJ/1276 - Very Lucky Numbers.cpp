#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t,bb=1;
    cin>>t;
    while(t--)
    {
        ll a,b,i,cnet=0;
        cin>>a>>b;
        for(i=a;i<=b;i++)
        {
            if(i==4)
            {
                cnet++;
                if(4*4<=b)cnet++;
            }
            if(i==7)
            {
                cnet++;
                if(7*7<=b)cnet++;
            }
            if(i%4==0 && i%7==0)
            {
            cout<<i<<endl;
                cnet++;
            }
        }

        cout<<"Case " <<bb<<": "<<cnet<<"\n";
        bb++;
    }

    return 0;

}
