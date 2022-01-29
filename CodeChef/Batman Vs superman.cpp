#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    auto it = lower_bound(v.begin(),v.end(),k);
    cout<<it-v.begin()+1<<endl;
    return 0;
}
