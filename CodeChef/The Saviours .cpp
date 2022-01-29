#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll tt=0,cnet=0,i,ss=s.size();
        stack<char>st;
        for(i=0; i<ss; i++)
        {
            if(s[i]=='*')
            {
                tt++;
            }
            if(s[i]=='0')
            {
                if(cnet==2)
                {
                    cnet=0;
                }
                else
                {
                    cnet++;
                }
            }
        }
        if(cnet==)
        {
            cout<<"YES\n";
        }
        else
            cout<<"NO\n";
    }
    return 0;

}
