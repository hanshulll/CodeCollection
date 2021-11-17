#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Mx 1000000

char prime[Mx];

void sieve()
{
    ll i,j;
    prime[0]=prime[1]=1;
    for(i=4; i<=Mx; i+=2)
        prime[i]=1;
    prime[2]=0;
    for(i=3; i<=sqrt(Mx); i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i; j<=Mx; j+=i)
            {
                prime[j]=1;
            }
        }
    }
}

int main()
{
    sieve();
    ll t,n;
    cin>>t;
    if(prime[t]==0)
        cout<<"NO PUNISHMENT\n";
    else
    {
        while(t--)
        {
            cout<<"I DID NOT DO THE ASSIGNMENT.\n";
        }
    }

    return 0;
}
