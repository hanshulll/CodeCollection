#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
#define ll long long int
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
//typedef  long long  int ll;
#define f(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define rf(i, a, b) for (ll i = (ll)a; i >= (ll)b; i--)
#define test  \
    ll T;     \
    cin >> T; \
    while (T--)
#define pb push_back
//#define PI 3.14159265
#define pii pair<ll, ll>
#define VP vector<pii>
#define Sort(v) sort(v.begin(), v.end())
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define vec vector<ll>
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define max4(a, b, c, d) max(a, max3(b, c, d))
#define min4(a, b, c, d) min(a, min3(b, c, d))
const ll MOD = 1000000000 + 7;
const ll MOD1 = 998244353;
 
 vector<ll>adj[100001];
 ll vis[100001];
 
stack<ll>ss;
set<ll>ins;
ll ck=0;
void dfs(ll sr)
{
    vis[sr]=1;
    for(auto it: adj[sr])
    {
        if(vis[it]==1)
         ck=1;
        else if(vis[it]==0)
        {
            dfs(it);
        }
        if(ck)
        return;
    }
    vis[sr]=2;
    ss.push(sr);
    return;
}
 
 
 
int main()
{
    fast;
   
   ll n,m;
   cin>>n>>m;
    f(i,0,m)
    {
        ll a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }
    
    f(i,1,n+1)
    vis[i]=0;
 
  f(i,1,n+1)
  {
      if(!vis[i])
      dfs(i);
      if(ck)
      break;
  }
    if(ck>0)
    cout<<"IMPOSSIBLE\n";
    else
    {
        while(!ss.empty()){
        cout<<ss.top()<<" ";
        ss.pop();}
    }
    
 
    cerr << "Time Elapsed : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}
 
/* */