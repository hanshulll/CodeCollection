
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        set<int>s;
        int n,a;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            s.insert(arr[i]);
        }
        cout<<s.size()<<endl;
        s.clear();
    }
}
