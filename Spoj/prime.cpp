#include <iostream>
typedef long long int ll;
using namespace std;

int isPrimeNumber(int);

int main()
{
    bool isPrime;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=n;i<=m;i++)
        {
            isPrime = isPrimeNumber(i);

            if(isPrime == true)
            {
                if(i==1)continue;
                else cout<<i<<endl;
            }

        }
    }

    return 0;
}

int isPrimeNumber(int n)
{
    bool isPrime = true;

    for(int i=2;i<=n/2;i++)
    {
        if (n%i==0)
        {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}
