#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int ss=s.size();
    stack<char>st;
    for(int i=0; i<ss; i++)
    {
        if(!st.empty())
        {
            if(st.top()=='(' && s[i]==')')
            {
                st.pop();
            }
            else if(st.top()=='{' && s[i]=='}')
            {
                st.pop();
            }
            else if(st.top()=='[' && s[i]==']')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        else
        {
            st.push(s[i]);
        }
    }
    if(st.empty())
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    return 0;
}
