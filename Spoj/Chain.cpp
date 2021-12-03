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
int root[MAX], d[MAX];

int find(int u) {
	if(u == root[u]) return u;
	int tmp = root[u];
	root[u] = find(root[u]);
	d[u] = d[tmp] + d[u];
	return root[u];
}

int main() {
	int test, cs, n, k, i, t, x, y, px, py, ans, tmp;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &k);
		for(i = 1; i <= n; i++) {
			root[i] = i;
			d[i] = 0;
		}
		ans = 0;
		while(k--) {
			scanf("%d %d %d", &t, &x, &y);
			if(x > n || y > n) { ans++; continue; }
			px = find(x);
			py = find(y);
			t--;
			if(px == py) {
				tmp = (d[x] - d[y]) % 3; if(tmp < 0) tmp += 3;
				if(tmp != t) ans++;
			}
			else {
				root[px] = py;
				i = (d[x] - d[y] - t) % 3;
				d[px] = i < 0? -i : -i+3;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
