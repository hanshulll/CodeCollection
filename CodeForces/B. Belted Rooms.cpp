#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        string s,f="AB",v="BB";
        cin>>s;
        long long ss=s.size();
        long long pos = string::npos;
        while (ss!=0)
        {
            if((pos  = s.find(f) )!= string::npos)
            {
                s.erase(pos, f.length());
            }
            else if((pos  = s.find(v) )!= string::npos)
            {
                s.erase(pos, v.length());
            }
            else break;
        }

        cout<<s.size()<<endl;
    }

    return 0;
}
