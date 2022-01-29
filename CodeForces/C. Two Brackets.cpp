#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int len=s.size();
        int cnet=0,nn=0,mm=0,mx=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='(')
            {
                nn++;
            }
            else if(s[i]=='[')
            {
                mm++;
            }
            else if(s[i]==')' && nn>0)
            {
                nn--;
                cnet++;
            }
            else if(s[i]==']' && mm>0)
            {
                mm--;
                cnet++;
            }
        }
        cout<<cnet<<endl;
    }
}
