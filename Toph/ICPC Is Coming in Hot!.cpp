#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    map<char,int>mp;
    string s;
    cin>>s;
    int i,ss=s.size();
    for(i=0;i<ss;i++)
    {
        mp[s[i]]++;
    }
    int m=0;
    char ch;
    for(i='0';i<='9';i++)
    {
       if(mp[i]>m)
       {
           m=mp[i];
           ch=i;
       }
    }

    cout<<ch<<endl;

    return 0;
}
