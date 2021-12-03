#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cnet=1;
    cin>>n;
    while(n--)
    {
        double a,b,c,d;
        cin>>a>>b>>c>>d;
        double m=sqrt(d/(d+1))*a;
        cout<<"Case "<<cnet<<": "<<setprecision(10)<<m<<"\n";
        cnet++;
    }
    return 0;
}
