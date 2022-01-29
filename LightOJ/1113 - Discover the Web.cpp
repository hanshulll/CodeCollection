#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t,i;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cout<<"Case "<<i<<":"<<"\n";
        stack<string>fd,bk;
        bk.push("http://www.lightoj.com/");
        string s1,s2;
        while(cin>>s1)
        {
            if(s1=="QUIT")
            {
                break;
            }
            else if(s1=="VISIT")
            {
                cin>>s2;
                bk.push(s2);
                cout<<bk.top()<<"\n";

                if(!fd.empty())
                {
                    while(!fd.empty())
                    {
                        fd.pop();
                    }
                }
            }
            else if(s1=="BACK")
            {
                if(bk.size()<=1)
                {
                    cout<<"Ignored\n";
                }
                else
                {
                    fd.push(bk.top());
                    bk.pop();
                    cout<<bk.top()<<"\n";
                }
            }
            else
            {
                if(fd.empty())
                {
                    cout<<"Ignored\n";
                }
                else
                {
                    bk.push(fd.top());
                    fd.pop();
                    cout<<bk.top()<<"\n";
                }
            }

        }

    }
    return 0;
}
