#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int>m;
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;

        if(m[s]==0)
        {
            m[s]=1;
            cout<<"OK\n";

        }
        else
        {
            cout<<s<<m[s]<<endl;
            m[s]++;
        }
    }
    return 0;
}
