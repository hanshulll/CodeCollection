#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        if(s=="0")break;
        ll i,len=s.size();
        ll shes=0;
        for(i=0; i<len; i++)
        {
            shes = ((shes*10) + (s[i]-'0'))%11;
        }
        if(shes==0)
            cout<<s<<" is a multiple of 11.\n";
        else
            cout<<s<<" is not a multiple of 11.\n";

    }

    return 0;

}
