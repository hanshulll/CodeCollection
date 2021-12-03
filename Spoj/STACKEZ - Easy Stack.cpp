#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    stack<ll>ss;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n==1)
        {
            ll m;
            cin>>m;
            ss.push(m);
        }
        else if(n==2)
        {
            if(!ss.empty())
            {
                ss.pop();
            }
        }
        else
        {
            if(!ss.empty())
            {
                cout<<ss.top()<<endl;
            }
            else
                cout<<"Empty!\n";
        }
    }
    return 0;
}
