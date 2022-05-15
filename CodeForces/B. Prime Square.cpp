#include<bits/stdc++.h>
using namespace std;
int main()

{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i==n && j==1)
                {
                    cout<<"1 ";
                }
                else if(i==j || i+1==j)
                {
                    cout<<"1 ";
                }
                else cout<<"0 ";
            }
            cout<<"\n";
        }
    }
    return 0;

}
