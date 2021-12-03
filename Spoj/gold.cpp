
#include<bits/stdc++.h>
#define ll long long
#define Mx 10000000
using namespace std;

bool prime[Mx+10];

ll arr[1000000],k=0;

void sieve()
{
    ll i,j;
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(i=2; i<=Mx; i++)
    {
        if(prime[i]==true)
        {
            arr[k++]=i;
        }
        for(j=i*2;j<=Mx;j+=i){
            prime[j]=false;
        }
    }
    return ;
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
                if(prime[n-arr[i]]==true)
                {
                    cnet++;
                    //cout<<"YES\n";
                }
                // else cout<<"NO\n";
            }
            printf("Case %lld: %lld\n",cnt,cnet);

        cnt++;


    }

    return 0;

}

