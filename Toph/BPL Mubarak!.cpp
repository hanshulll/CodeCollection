#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
read:
    while(t--)
    {
        string s;
        cin>>s;
        int cnet=0,ov=0;
        int i,ss=s.size();
        for(i=0; i<ss; i++)
        {
            if(s[i]=='N' || s[i]=='W' || s[i]=='D')
            {
                continue;
            }
            else
            {
                cnet++;
            }
            if(cnet==6)
            {
                cnet=0;
                ov++;
            }
        }
        string ball,ovr;
        if(cnet==1)
        {
            ball="BALL";
        }
        else if(cnet>1)
        {
            ball="BALLS";
        }
        if(ov==1)
        {
            ovr="OVER";
        }
        else if(ov>1)
        {
            ovr="OVERS";
        }

        if(ov!=0 && cnet!=0)
        {
            cout<<ov<<" "<< ovr<<" "<<cnet<<" "<<ball<<endl;
        }
        else if(ov!=0 && cnet==0)
        {
            cout<<ov<<" "<<ovr<<endl;
        }
        else
            cout<<cnet<<" "<<ball<<endl;


    }

    return 0;
}
