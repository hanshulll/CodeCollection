#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        stack<char>st;
        int ss=s.size();
        int ans=0,sum=0;
        for(int i=0; i<ss; i++)
        {
            if(s[i]=='(' || s[i]=='[')
                st.push(s[i]);
            else
            {
                if(!st.empty())
                {
                    if(st.top()=='(' && s[i]==')')
                    {
                        sum+=2;
                        st.pop();
                    }
                    else if(st.top()=='[' && s[i]==']')
                    {
                        sum+=2;
                        st.pop();
                    }
                    else
                    {
                        sum=0;
                        while(!st.empty())
                        {
                            st.pop();
                        }
                    }
                }
                else
                {
                    sum=0;
                }
            }
            ans=max(ans,sum);
            if(st.empty())
            {
                sum=0;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
