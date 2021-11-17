#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll cnet=0,len=s.size();
        char s1=s[n-1];
        for(int i=0;i<len;i++)
        {
            if(s[i]==s1)cnet++;
        }
        if(cnet>=2)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
