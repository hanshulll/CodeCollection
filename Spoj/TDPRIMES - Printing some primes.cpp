#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int i,j,m=100000000;
    //const int m=1e8;
    vector<long long int>v;
    vector<bool>prime(m+1,true);
    prime[0]=prime[1]=false;
    for(i=2; i<=sqrt(m); i++)
    {
        if(prime[i])
        {
            for(j=i*i; j<=m; j+=i)
            {
                prime[j]=false;
            }
        }
    }
    for(i=2; i<=m; i++)
    {
        if(prime[i])
        {
            v.push_back(i);
        }
    }
    for(i=1;i<v.size();i+=100)
    {
        cout<<v[i-1]<<endl;
    }

    return 0;
}
