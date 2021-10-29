#include <bits/stdc++.h>
#define ll long long
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define F first
#define S second
#define setbit(n) __builtin_popcountll(n)
#define all(x) x.begin() , x.end()
#define clr(x) memset(x,0,sizeof(x))
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define endl "\n" //delete if interactive
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve()
{
    int n , k ;
    cin >> n >> k ;
    if (k == 0) {
        cout << "YES\n0\n"; return;
    }
    if (k % 2 == 0) {
        cout << "NO\n"; return;
    }
    int bit = 0 ;
    for (int i = 31; i >= 0; i--) {
        if (((1 << i)&k)) {bit = i + 1 ; break;}
    }
    int ans = 1;
    vector<int> arr;
    k = ((1 << bit) + k - 1 ) / 2 ;
    for (int i = bit - 2 ; i >= 0; i--) {
        if (!((1 << i)&k)) {
            ans -= (1 << i);
            arr.push_back(ans);
        }
        else {
            arr.push_back(ans);
            ans += (1 << i);
        }
    }
    cout << "YES" << endl;
    cout << bit << endl;
    for (int i = bit - 2; i >= 0; i--)
        cout << arr[i] << endl;
    cout << ans << endl;
}
int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {solve();}
    return 0;

}

