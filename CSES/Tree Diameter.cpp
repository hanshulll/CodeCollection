#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

using namespace std;

// using namespace __gnu_pbds;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define f0(i,a,b) for(int i=a;i<b;i++)
#define f1(i,a,b) for(int i=a;i<=b;i++)
#define f2(i,a,b) for(int i=a;i>b;i--)
#define f3(i,a,b) for(int i=a;i>=b;i--)
#define f(i,m,n) for(auto i = ( m ); i <= ( n ); i ++)
#define _in(v) for(auto& _var:v)    cin>>_var;
#define _out(v) for(auto _var:v)    cout<<_var<<" ";
#define _rout(x) for(auto _it=x.rbegin(); _it!=x.rend(); _it++) cout<<(*_it)<<" ";
#define _all(x) x.begin(), x.end()
#define _rall(x) x.rbegin(), x.rend()
#define _loop(x) for(auto& _var:x)
#define _ms(x,n) memset(x,n,sizeof(x))
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define nl cout<<"\n";
#define loopt int _tc; cin>>_tc; while(_tc--)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#define fi first
#define se second
using ll = long long int;
using ull = unsigned long long int;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int,int>;
using pll = pair<long long int,long long int>;
using vpii = vector<pii >;
using vpll = vector<pll>;
using vvi = vector<vi >;
const ll INF = 1000000005;
const ll mod = ((int)1e9+7);
const ll mod1 = 998244353;

/////////////////////////////////\\\\

ll _fac(ll n, ll MOD = LLONG_MAX)   {return (n==1||n==0)?1:(n*((_fac(n-1))%MOD))%MOD;}

ll _pow(ll a, ll b, ll MOD = LLONG_MAX)
{
    if(b==0||a==1)  return 1;
    if(a==0)    return 0;
    if(b&1) {ll temp = _pow(a,b/2,MOD)%MOD; return (((temp*temp)%MOD)*a)%MOD;}
    else    {ll temp = _pow(a,b/2,MOD)%MOD; return (temp*temp)%MOD;}
}

ll _gcd(ll a, ll b) {if(b==0)    return a;   return _gcd(b,a%b);}

ll _lcm(ll a, ll b) {return (a*b)/_gcd(a,b);}

ll _mod(ll x)
{
    return (x%mod + mod)%mod;
}

ll _mul(ll a,ll b)
{
    return _mod(_mod(a)*_mod(b));
}

ll _nPr(ll n, ll r) {return _fac(n)/_fac(r);}

ll _nCr(ll n, ll r)

{
    if(r>n-r)   r = n-r;
    if(r==0)    return 1;
    ll n1 = 1;
    ll n2 = 1;
    f1(i,1,r)    n1*=i;
    f1(i,n-r+1,n)  n2*=i;
    return n2/n1;
}

ll _invMod(ll a, ll m)  {return _pow(a, m-2, m);}

ll _cat(int n)  {return _nCr(2*n,n)/(n+1);}

ll _msb(ll n)
{
    n |= n>>1;
    n |= n>>2;
    n |= n>>4;
    n |= n>>8;
    n |= n>>16;
    n |= n>>32;
    n++;
    return (n>>1);
}

int _nod(ll n)  {int c = 0;  while(n>0)  {c++; n/=10;}   return c;}

int _nob(ll n)  {int c = 0;  while(n>0)  {c++; n&=(n-1);}   return c;}

bool _isPrime(ll n, int k = 5)
{
    if(n<=1||n==4)  return false;
    if(n<=3)    return true;
    while(k>0)
    {
        ll a = 2 + rand()%(n-4);
        if(_gcd(n,a)!=1)    return false;
        if(_pow(a,n-1,n)!=1)    return false;
        k--;
    }
    return true;
}

void _file()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

/////////////////////////////////\\\\\\\\

vector<int> arr[200001];
bool vis[200001];
int maxd=-1,maxNode;

void dfs(int node,int d){

    vis[node] = 1;
    if(d>maxd)
    {
        maxd = d;
        maxNode = node;
    }

    for(int child: arr[node])
    {
        if(vis[child]==0)
        {
            dfs(child,d+1);
        }
    }

}

int main(){
    int n;cin>>n;
    int m = n-1;

    while(m--)
    {
        int a,b;
        cin>>a>>b;
        arr[a].pb(b);
        arr[b].pb(a);
    }

    dfs(1,0);

    f1(i,1,n) vis[i]=0;

    maxd = -1;

    dfs(maxNode,0);

    cout<<maxd;

}