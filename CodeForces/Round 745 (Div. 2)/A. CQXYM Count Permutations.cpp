#include <iostream>
using namespace std;
#define mp make_pair
#define ff first
#define ss second
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define PT 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define pb push_back
#define ppb pop_back

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifdef SOLUTION
#define debug(x) cerr << #x <<" "; _print(x); cerr <<endl;
#else
#define debug(x)
#endif

int main() 
{
#ifdef SOLUTION
    freopen("Error.txt","w",stderr);
#endif
ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int t;
cin>>t;
while(t--){
int n;
      cin>>n;
      ll op=1;
      ll modulo=1e9+7;
      for(int i=2*n;i>=3;i--)
        op=(op*i)%modulo;;
      op=op%modulo;
      cout<<op<<endl;
}
return 0;
}