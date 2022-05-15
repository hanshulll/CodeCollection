#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define Mx 1000000

char prime[Mx];
ll dg[Mx];
ll arr[Mx],k=0;
void sieve()
{
    ll i,j,p;
    prime[0]=prime[1]=1;
    for(i=4; i<=Mx; i+=2)
        prime[i]=1;
    for(i=3; i<=sqrt(Mx); i+=2)
    {
        if(prime[i]==0)
        {
            ll sum=0,p=i;
            while(p>0)
            {
                ll x=p%10;
                sum+=x;
                p/=10;
            }
            if(prime[sum]==0)
            {
                arr[i]=1;
            }
            for(j=i*i; j<=Mx; j+=i)
            {
                prime[j]=1;
            }
        }
    }
    for(i=2;i<=Mx;i++)
    {
        arr[i]=arr[i]+arr[i-1];
    }

}

int main()
{
    sieve();
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",arr[b]-arr[a-1]);
    }

    return 0;
}
