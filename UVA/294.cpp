#include<bits/stdc++.h>
using namespace std;
//Welcome To Hridoy's Code
#define   ll                  long long
#define   ull                 unsigned long long
#define   pb                  push_back
#define   em                  emplace_back
#define   ff                  first
#define   ss                  second
#define   endl                "\n"
#define   MX                  10000009
#define   all(v)              (v.begin(), v.end())
#define   rall(v)             (v.rbegin(), v.rend())
#define   pi                  acos(-1.0)
#define   LCM(LCM_X,LCM_Y)    (LCM_X/__gcd(LCM_X,LCM_Y))*LCM_Y
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
char prime[MX];
ll arr[MX],k=1;
void sieve()
{
    ll i,j;
    prime[0]=prime[1]=1;
    for(i=4; i<=MX; i+=2)
        prime[i]=1;
    for(i=3; i<=sqrt(MX); i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i; j<=MX; j+=2*i)
            {
                prime[j]=1;
            }
        }
    }
    for(i=2; i<=MX; i++)
    {
        if(prime[i]==0)
        {
            arr[k++]=i;
        }
    }

}
int main()
{
    sieve();
    ll t,n,r,s,c,i,l;
    cin>>t;
    while(t--)
    {
        ll bal=0;
        ll sal=0;
        ll p,m;
        cin>>p>>m;
        for(i=p; i<=m; i++)
        {
            n=i;
            r=1;
            s=0;
            for(l=1; arr[l]<=sqrt(n); l++)
            {
                c=0;
                if(n%arr[l]==0)
                {
                    while(n%arr[l]==0)
                    {
                        c++;
                        n/=arr[l];
                        if(n==1 || n==0)
                            break;
                    }
                    s=c+1;
                    r*=s;
                }
            }
            if(n!=1)
                r*2;
            if(r>bal)
            {
                bal=r;
                sal=i;
            }
        }
        cout<<"Between "<<p<<" and "<<m<<","<<sal<<" has a maximum of "<<bal<<" divisors."<<endl;
    }
    return 0;
}

