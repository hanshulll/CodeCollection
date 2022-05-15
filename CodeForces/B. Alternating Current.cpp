#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    stack<char>st;
    int i,ll=s.size();
    bool flag=false;
    for(i=0; i<ll; i++)
    {
        if(!st.empty())
        {
            if(st.top()=='+' && s[i]=='+')
            {
                st.pop();
            }
            else if(st.top()=='-' && s[i]=='-')
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
    cout<<(st.empty()? "YES":"NO")<<endl;
    return 0;
}
