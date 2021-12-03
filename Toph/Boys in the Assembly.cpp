#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    long long int a;
    vector<long long int>v;

    for(int i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
    }
    while(m--)
    {
        reverse(v.begin(),v.end());
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
