#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Mx 100000000

char prime[Mx];
ll arr[Mx],k=1;
void sieve()
{
    ll i,j;
    prime[0]=prime[1]=1;
    for(i=4;i<=Mx;i+=2)prime[i]=1;
    for(i=3;i<=sqrt(Mx);i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=Mx;j+=2*i)
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
    ll t,n;
    cin>>t;
    cout<<arr[t]<<endl;

    return 0;
}

