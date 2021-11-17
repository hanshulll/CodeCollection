#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define Mx 1000000

char prime[Mx];

void sieve()
{
    ll i,j;
    prime[0]=prime[1]=1;
    for(i=4;i<=Mx;i+=2)prime[i]=1;
    prime[2]=0;
    for(i=3;i<=sqrt(Mx);i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i;j<=Mx;j+=i)
            {
                prime[j]=1;
            }
        }
    }
    //cout<<prime[2]<<endl;
}

int main()
{
    sieve();
    ll t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;

        if(prime[n]==0)
        {
            cout<<n<<" is a prime number.\n";
        }
        else cout<<n<<" is not a prime number.\n";
    }

    return 0;
}
