#include<bits/stdc++.h>

using namespace std;
#define mx  10000009

typedef long long ll;

vector < int > primes;

void sieveOfEratosthenes()
{
    bool flag[mx+1];
    for(int i=0 ; i<=mx ; i++)
        flag[i]=true;
    primes.push_back(2);

    flag[0]=flag[1]=false;

    for(int i=4 ; i<=mx ; i+=2)
    {
        flag[i]=false;
    }

    for(int i=3 ; i<=mx ; i+=2)
    {
        if(flag[i]==true) /// i is prime
        {
            primes.push_back(i);
            for(int j=i+i ; j<=mx ; j=j+i)
            {
                flag[j]=false; ///j is not prime
            }
        }
    }
}


void segmentedSieve(ll L, ll R)
{
    ll cnet=0;
    bool isPrime[R-L+1];
    for(int i=0 ; i<=R-L+1 ; i++)
        isPrime[i]=true;


    if(L==1)
        isPrime[0]=false;
    for(int i=0 ; primes[i]*primes[i]<=R ; i++)
    {
        ll curPrime=primes[i];
        ll base=curPrime*curPrime;
        if(base<L)
        {
            base=((L+curPrime-1)/curPrime)*curPrime;
        }
        for(ll j=base ; j<=R ; j+=curPrime)
            isPrime[j-L]=false;
    }
    for(int i=0 ; i<=R-L ; i++)
    {
        if(isPrime[i]==true)
            cnet++;
    }
    cout<<cnet<<"\n";
}
int main()
{
    sieveOfEratosthenes();
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        segmentedSieve(a,b);
    }
    return 0;
}
