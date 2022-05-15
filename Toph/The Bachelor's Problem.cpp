#include<bits/stdc++.h>

#define ll long long
using namespace std;

int main()
{
    ll t,i=0,j=0,k=1;
    cin>>t;
    while(t--)
    {
        ll m1,m2,m3,m4,m5,m6,sum=0;
        cin>>m1>>m2>>m3>>m4>>m5>>m6;
        sum+=m1+m2+m3+m4+m5+m6;
        ll tol,n1,n2,n3,n4,n5,n6,dum=0;
        cin>>tol;
        cin>>n1>>n2>>n3>>n4>>n5>>n6;
        dum+=n1+n2+n3+n4+n5+n6;
        ll bil =(dum-(tol-sum));
        if(bil<=0)
        {
            bil=0;
        }
        cout<<"Case "<<k<<": "<<bil<<endl;
        k++;
    }

    return 0;
}


