#include <bits/stdc++.h>
using namespace std;

typedef signed i32;
typedef unsigned u32;
typedef long long i64;
typedef unsigned long long u64;
// typedef __int128_t i128;
// typedef __uint128_t u128;
typedef float f32;
typedef double f64;
typedef long double f128;

const int maxn = (int)4e3 + 1, maxm = (int)4e6 + 1;
const int maxd = 21, maxc = 26;
const int mod = (int)1e9 + 7, INF = 0x3f3f3f3f, inv2 = (mod + 1) >> 1;
const f64 pi = acos((f64) - 1), eps = 1e-12;

inline int sgn(f64 x) {
	return (x > eps) - (x < -eps);
}

void solve() {
	int n, m;
	static int a[maxn];
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);

	int prd = 1;
	static int dp[maxn][maxn];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j) {
			if (a[i] >= a[j]) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = (a[j] - a[i]) % mod;
		}
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		prd = (prd << 1) % mod;
		int com = (i64)(dp[u][v] + dp[v][u]) * inv2 % mod;
		dp[u][v] = dp[v][u] = com;
		for (int x = 1; x <= n; ++x) {
			if (x == u || x == v)
				continue;
			int com = (i64)(dp[x][u] + dp[x][v]) * inv2 % mod;
			dp[x][u] = dp[x][v] = com;
		}
		for (int y = 1; y <= n; ++y) {
			if (y == u || y == v)
				continue;
			int com = (i64)(dp[u][y] + dp[v][y]) * inv2 % mod;
			dp[u][y] = dp[v][y] = com;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			ans = (ans + (i64)(j - i) * dp[i][j]) % mod;
	ans = (i64)ans * prd % mod;
	printf("%d\n", ans);
}

int main() {
	int T = 1;
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case) {
		// printf("Case #%d: ", Case);
		// printf("%d\n", solve());
		solve();
	}
	return 0;
}