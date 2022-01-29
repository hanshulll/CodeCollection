#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cin>>a;
    cin>>b;
    int s1=0,s2=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
           s1+=a[i]-'0';
        }
    }
    for(int i=0;i<b.size();i++)
    {
        if(b[i]>='0' && b[i]<='9')
        {
            s2+=b[i]-'0';
        }
    }
    char l='"';
    int ans=s1+s2;
    cout<<l<<ans<<l<<endl;
}
