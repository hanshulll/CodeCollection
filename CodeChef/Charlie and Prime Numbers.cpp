#include<bits/stdc++.h>
#define ll long long
#define Mx 5000001
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
    //cout<<arr[12]<<endl;
}
int main()
{
    sieve();
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,sum=0,i;
        cin>>a>>b;
        for(i=a;i<=b;i++)
        {
            if(prime[i]==0)
            {
               sum+=i;
            }
        }

        cout<<sum<<endl;
    }

    return 0;

}
