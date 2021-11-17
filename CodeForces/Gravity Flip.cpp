#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    vector<int>v;
    cin>>n;
    while(n--)
    {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
