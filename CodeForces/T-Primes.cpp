#include<bits/stdc++.h>
using namespace std;

#define Mx 10000000
char prime[Mx];
int arr[Mx],k=0;

void sieve()
{
    long long i,j;
    prime[0]=prime[1]=1;
    for(i=4; i<=Mx; i+=2)
        prime[i]=1;
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
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long sq=sqrt(n);
        if(n<4)
        {
            cout<<"NO\n";
            continue;
        }
        else if(n==(sq*sq) && prime[sq]!=1)
                {
                    cout<<"YES\n";
                    continue;
                }
        else
        {
            cout<<"NO\n";
                continue;
        }

    }

    return 0;
}
