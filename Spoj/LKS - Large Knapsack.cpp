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
int wt[12345],val[12345];
int kp(int val[],int wt[],int n,int w)
{
    int i,j;
    int k[w+1];
    memset(k,0,sizeof(k));
    for(i=0; i<n; i++)
    {
        for(j=w; j>=wt[i]; j--)
        {
            k[j]=max(k[j],val[i]+k[j-wt[i]]);
        }
    }
    return k[w];
}
int main()
{
    FastRead
    int n,m,i;
    cin>>m>>n;
    for(i=0; i<n; i++)
        cin>>val[i]>>wt[i];

    cout<<kp(val,wt,n,m)<<endl;

    return 0;
}
