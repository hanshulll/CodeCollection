#include<bits/stdc++.h>
#define ll int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    while(m--)
    {
        ll op,cnet=0;
        cin>>op;
        if(op==2)
        {
            ll st,en,i;
            char ch;
            cin>>st>>en>>ch;
            for(i=st-1;i<=en-1;i++)
            {
                if(s[i]==ch)cnet++;
            }
            cout<<cnet<<"\n";

        }
        else
        {
            ll in;
            char ss;
            cin>>in>>ss;
            s[in-1]=ss;
        }

    }
    return 0;
}
