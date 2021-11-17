#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    ll r,g,b,cnet=0;
    cin>>r>>g>>b;
    while(r!=0 && g!=0 && b!=0)
    {
        if(r>=3)
        {
            r-=3;
            cnet++;
        }
        if(g>=3)
        {
            g-=3;
            cnet++;
        }
        if(b>=3)
        {
            b-=3;
            cnet++;
        }
        else if(r<3 || g<3 || b<3)
        {
            r-=1;
            g-=1;
            b-=1;
            cnet++;
        }
    }
    cout<<cnet<<endl;

    return 0;
}
