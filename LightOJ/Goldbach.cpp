#include<bits/stdc++.h>
#define ll long long
#define Mx 100000000
using namespace std;

char prime[Mx];

ll arr[1000000],k=0;

void sieve()
{
    int i,j;
    prime[0]=prime[1]=1;
    for(i=4; i<=Mx; i+=2)
        prime[i]=1;
    for(i=3; i<=sqrt(Mx); i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i; j<=Mx; j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
  /*  for(i=2; i<=Mx; i++)
    {
        if(prime[i]==0)
        {
            arr[k++]=i;
        }
    }
    */
}
int main()
{
    sieve();
    ll t,cnt=1;;
    scanf("%lld",&t);
    while(t--)
    {
        ll n,cnet=0;
        scanf("%lld",&n);

            for(ll i=0; arr[i]<=n/2; i++)
            {
                if(prime[n-arr[i]]==0)
                {
                    cnet++;
                    //cout<<"YES\n";
                }
                // else cout<<"NO\n";
            }
            printf("Case %lld : %lld\n",cnt,cnet);

        cnt++;


    }

    return 0;

}

