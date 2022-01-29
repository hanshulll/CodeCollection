#include<bits/stdc++.h>
#define ll long long
#define Mx 10000000
using namespace std;

char prime[Mx];

ll arr[Mx],k=0;

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
    cout<<arr[0];
}
int main()
{
    sieve();
    ll n;
    cin>>n;

    return 0;

}
