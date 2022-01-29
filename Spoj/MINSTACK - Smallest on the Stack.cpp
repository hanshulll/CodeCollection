#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    ll mini=99999999;
    stack<ll>st;
    stack<ll>mn;
    while(t--)
    {
        string s;
        cin>>s;
        if(s=="PUSH")
        {
            ll n;
            cin>>n;
            if(mini>n)
            {
                mini=n;
                mn.push(mini);

            }
            else
            {
                mn.push(mini);
            }

        }
        else if(s=="MIN")
        {
            if(mn.empty())
            {
                cout<<"EMPTY\n";
            }
            else

                cout<<mn.top()<<"\n";
            cout<<"\n";
        }
        else if(s=="POP")
        {
            if(!mn.empty())
            {
                mn.pop();
            }
            else cout<<"EMPTY\n";

        }
    }

    return 0;
}
