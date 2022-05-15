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
        int count=0,ans=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='W' || s[i]=='D' || s[i]=='N')
                continue;
            else
            {
                count++;
            }
            if(count==6)
            {
                ans++;
                count=0;
            }
        }
        string ab,bc;
        if(count>1)
            bc="BALLS";
        else if(count==1)
            bc="BALL";
        if(ans==1)
            ab="OVER";
        else if(ans>1)
            ab="OVERS";
        if(ans!=0 && count!=0 )
            cout<<ans<<" "<<ab<<" "<<count<<" "<<bc<<endl;
        else if(ans!=0 && count==0)
            cout<<ans<<" "<<ab<<endl;
        else
            cout<<count<<" "<<bc<<endl;
    }
    return 0;
}
