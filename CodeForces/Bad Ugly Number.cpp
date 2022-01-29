#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    ll t,n;
    cin>>t;
    read:
    while(t--)
    {
        cin>>n;
        if(n==1)
        {
            cout<<"-1\n";
            goto read;
        }
        else
        {
            cout<<"2";
            for(int i=1;i<n;i++)cout<<"3";
        }
        cout<<endl;
    }

    return 0;

}
