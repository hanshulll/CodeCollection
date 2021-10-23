#include<bits/stdc++.h>
using namespace std;

int rod_cut(int price[],int n)
{
    int i,j;
    int t[n+1][n+1];

    for(i=0;i<=n;i++)
        t[i][0]=0;
    
    for(j=0;j<=n;j++)
        t[0][j]=0;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i<=j)
                t[i][j]=max(price[i-1]+t[i][j-i],t[i-1][j]);
            else
                t[i][j]=t[i-1][j];
        }
    }

    return t[n][n];



}


int main()
{
    int i,n;
    cout<<"\nEnter the Size\n";
    cin>>n;
    int price[n];
    cout<<"\nEnter price\n";
    for(i=0;i<n;i++)
        cin>>price[i];

    cout<<"\nMaximum Profit - "<<rod_cut(price,n);
    return 0;
}
