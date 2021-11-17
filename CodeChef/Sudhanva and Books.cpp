#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n;
    cin>>n;
    stack<ll>st;
    while(n--)
    {
        ll m;
        cin>>m;
        if(m==-1)
        {
            if(!st.empty())
            {
               cout<<st.top()<<endl;
               st.pop();
            }
            else cout<<"kuchbhi?"<<endl;


        }
        else
        {
            ll x;
            cin>>x;
            st.push(x);
        }

    }

    return 0;

}
