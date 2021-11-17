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
#define   all(v)              (v.begin(), v.end())
#define   rall(v)             (v.rbegin(), v.rend())
#define   pi                  acos(-1.0)
#define   LCM(LCM_X,LCM_Y)    (LCM_X/__gcd(LCM_X,LCM_Y))*LCM_Y
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int MOD = (int)1e9+7;
const int MAX = 1e6;
int main()
{
	FastRead
    long int i,j,a,b,c,n,k,ans,rem;
    while(cin>>n>>a>>b>>c)
    {
          ans=0;
       for(i=0;i*a<=n;++i)
       {
           for(j=0;i*a+j*b<=n;++j)
           {
                rem=n-i*a-j*b;
                if(rem%c==0)
                {
                    k=rem/c;
                ans=max(ans,i+j+k);}
           }

       }
       cout<<ans<<endl;
    }
    return 0;
}

