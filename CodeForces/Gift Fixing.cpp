#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main()
{
    ll t,i;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[50],b[50],mna=1000000000,mnb=1000000000;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            mna=min(mna,a[i]);
        }
        //cout<<mna<<endl;
        for(i=0;i<n;i++)
        {
            cin>>b[i];
            mnb=min(mnb,b[i]);
        }
      // cout<<mnb<<endl;
        ll ans=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>mna && b[i]>mnb)
            {
                ll x=max(a[i]-mna,b[i]-mnb);
                ans+=x;
            }
            else if(a[i]>mna)
            {
                ans+=a[i]-mna;
            }
            else if(b[i]>mnb)
            {
                ans+=b[i]-mnb;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
