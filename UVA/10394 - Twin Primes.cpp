#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define Mx 20000001
int arr[Mx];
char prime[Mx]={0};
void sieve()
{
    ll i,j;
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
void twin()
{
    ll i,j,k=1;
    for(i=3; i<Mx; i++)
    {
        if(prime[i]==0 && prime[i+2]==0)
        {
            arr[k]=i;
            k++;
        }
    }
}
int main()
{
    sieve();
    ll t;
    twin();
    while(cin>>t)
    {
        cout<<"("<<arr[t]<<", "<<arr[t]+2<<")"<<endl;
    }
    return 0;
}
