#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
 
    int c,n,a[11],s,m[10000];
    cin>>c>>n;
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<=c;i++)
    m[i]=1010;
    m[0]=0;
    for(int j=1;j<=c;j++)
    {
    for(int i=0;i<n;i++)
    {if(a[i]<=j && m[j-a[i]]+1<m[j])
   m[j]=m[j-a[i]]+1;//cout<<m[j]<<"\n";}
            }
    }
    cout<<m[c]<<"\n";
    //system("pause");
    return 0;
    }
