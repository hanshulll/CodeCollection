#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,a,b;
    cin>>n>>m;
    set<int>s;

    while(n--)
    {
        cin>>a;
        s.insert(a);
    }
    while(m--)
    {
        cin>>b;
        s.insert(b);
    }
    vector<int>v;
    for( auto it=s.begin(); it != s.end(); ++it)
        v.push_back(*it);

    for(int i=0;i<v.size();i++)
    {
        if(i==v.size()-1)
        {
            cout<<v[i];
        }
        else
        {
            cout<<v[i]<<" ";
        }
    }
    return 0;

}
