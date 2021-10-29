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
    ll n  ;
    cin >> n ;
    vector<ll> arr(n);
    for (ll i = 0 ; i < n ; i++)
        cin >> arr[i];
    sort(all(arr));

    ll l = 1, r = n - 2;
    if (n == 2) {
        cout << 0 << endl;
        return;
    }
    ll d1 = 0  , d2 = 0;
    ll ans = INT_MAX;
    while (l < r)
    {
        d1 = arr[r] - arr[0];
        d2 = arr[n - 1] - arr[l];
        ans = min(ans, abs(d1 - d2));
        if (d1 >= d2)
            r--;
        else
            l++;
    }
    ll ans1 = 0, ans2 = 0;
    for (ll i = 0; i < n - 1; i++)
        ans1 += abs(arr[(n - 1) / 2] - arr[i]);
    for (ll i = 1; i < n; i++)
        ans2 += abs(arr[(n - 1) / 2 + 1] - arr[i] );

    ll final  = min({ans , ans1, ans2});
    cout << final << endl;
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

