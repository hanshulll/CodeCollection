#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1;
    cin>>s1;
    string s2=string(s1.rbegin(),s1.rend());
    if(s1==s2)cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}
