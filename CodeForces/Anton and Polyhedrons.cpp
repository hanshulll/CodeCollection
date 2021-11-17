#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=0;
    while(n--)
    {
        string s;
        cin>>s;
        if(s=="Icosahedron")
        {
            ans+=20;
        }
        else if(s=="Cube")
        {
            ans+=6;
        }
        else if(s=="Tetrahedron")
        {
            ans+=4;
        }
        else if(s=="Dodecahedron")
        {
            ans+=12;
        }
        else if(s=="Octahedron")
        {
            ans+=8;
        }

    }
    cout<<ans<<endl;

    return 0;
}
