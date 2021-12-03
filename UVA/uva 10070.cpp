#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll rem(string s,ll n)
{
    ll y=0,i,len=s.size();
    for(i=0;i<len;i++)
    {
        y=((y*10)+(s[i]-'0'))%n;
    }
    return y;
}

int main()
{
    ll i;
    ll p=0;
    string s;
    while(cin>>s)
    {
        if(p!=0)cout<<"\n";
        p++;
        ll l=0,h=0,b=0;
        ll len=s.size();
        if(((rem(s,4)==0) && (rem(s,100)!=0)) || (rem(s,400)==0))
        {
            cout<<"This is leap year.\n";
            l=1;
        }
        if(rem(s,15)==0)
        {
            cout<<"This is huluculu festival year.\n";
            h=1;
        }
        if(rem(s,55)==0 && l==1)
        {
            cout<<"This is bulukulu festival year.\n";
            b=1;
        }
        if(b==0 && l==0 && h==0)
        {
            cout<<"This is an ordinary year.\n";
        }

    }


    return 0;
}
