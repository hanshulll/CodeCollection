#include<bits/stdc++.h>
using namespace std;
int main()
{
    int k=1,i;
    string s;
    while(cin>>s)
    {
        stack<char>st;
        int cnet=0;
        int ss=s.size();
        for(i=0; i<ss; i++)
        {
            if(s[i]=='-')
            {
                return 0;
            }
            if(s[i]=='}')
            {
                if(st.empty())
                {
                    cnet++;
                    st.push(s[i]);
                   // cout<<cnet<<endl;
                }
                else
                {
                    st.pop();
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
        if(!st.empty())
        {
            cnet+=st.size()/2;
        }
        cout<<k<<". "<<cnet<<endl;
        k++;
    }
    return 0;
}
