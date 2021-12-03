#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define Mx 100000000
vector<bool>prime(Mx+1,true);
ll arr[Mx],k=1;
void sieve()
{

    ll i,j;
    prime[0]=prime[1]=false;
    for(i=4;i<=Mx;i+=2)prime[i]=false;
    for(i=3;i<=sqrt(Mx);i+=2)
    {
        if(prime[i])
        {
            for(j=i*i;j<=Mx;j=j+2*i)
            {
                prime[j]=false;
            }
        }
    }
    arr[0]=2;
    for(i=3;i<=Mx;i+=2)
    {
        if(prime[i])
        {
            arr[k++]=i;
        }
    }
}

int main()
{
    sieve();
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<arr[n-1]<<endl;
    }
    return 0;
}
