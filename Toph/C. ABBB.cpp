#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
       stack<ll>st;
       string s;
       cin>>s;
       ll i,cnet=0,ss=s.size();
       for(i=0;i<ss;i++)
       {
           if(s[i]=='B' && cnet>0)
           {
               cnet--;
           }
           else
           {
               cnet++;
           }
       }

       cout<<cnet<<endl;
   }
}
