#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string s;
    cin>>s;
    ll i,ss=s.size(),cnet=0,sum=0,mx=0;
    stack<char>st;
    for(i=0; i<ss; i++)
    {
        if(s[i]=='(')
        {
            st.push(s[i]);
        }
        if(!st.empty())
        {
            if(st.top()=='(' && s[i]==')')
            {
                st.pop();
                cnet++;
                mx=max(mx,cnet);
            }
            if(st.empty())
            {
                //cnet=0;
                sum++;
            }
        }
    }
    if(st.empty())
    {
        cout<<mx*2<<" "<<sum<<endl;
    }
    else
        cout<<"0 1"<<endl;

    return 0;
}
