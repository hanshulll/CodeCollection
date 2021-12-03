#include<bits/stdc++.h>
using namespace std;

#define Mx 100000000

char prime[Mx];
int arr[Mx],k=0;
void sieve()
{
    long long int  i,j;
    prime[0]=prime[1]=1;
    for(i=4;i<=Mx;i+=2)prime[i]=1;
    for(i=3;i<=sqrt(Mx);i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=Mx;j+=i)
            {
                prime[j]=1;
            }
        }
    }
    for(i=2;i<=Mx;i++)
    {
        if(prime[i]==0)
        {
            arr[k++]=i;
        }
    }

}
int main()
{
    sieve();
    long long int t;

    while(cin>>t && t!=0)
    {
        long long int x,y,flag=0,i;
        for(i=0;i<=Mx;i++)
        {
            x=arr[i],y=t-arr[i];
            if(x>y)break;
            if(prime[x]==0 && prime[y]==0)
            {
                cout<<t<<" = "<<x<<" + "<<y<<endl;
                flag=1;
                break;

            }
        }
        if(flag==0)cout<<"Goldbach's conjecture is wrong.\n";
    }

    return 0;
}
