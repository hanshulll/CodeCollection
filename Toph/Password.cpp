#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int cnet=0;
        int ss=s.size();
        int dg=0,lw=0,up=0;
        for(int i=0; i<ss; i++)
        {
            if(islower(s[i]))
            {
                lw++;
                if(dg!=0 && up!=0 && lw!=0)
                {
                    cnet++;
                    dg=0;
                    up=0;
                    lw=0;
                }
            }

            else if(isupper(s[i]))
            {
                up++;
                if(dg!=0 && up!=0 && lw!=0)
                {
                    cnet++;
                    dg=0;
                    up=0;
                    lw=0;
                }
            }

            else if(s[i]>='0' && s[i]<='9')
            {
                dg++;
                if(dg!=0 && up!=0 && lw!=0)
                {
                    cnet++;
                    dg=0;
                    up=0;
                    lw=0;
                }
            }


        }
        cout<<cnet<<endl;
    }

    return 0;
}
