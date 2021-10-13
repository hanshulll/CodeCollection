int n;
vi adj[MX];
bool done[MX];
int ans = 0;

void dfs(int pre, int cur) {
	for (int i: adj[cur]) {
		if (i != pre) {
			dfs(cur,i);
			if (!done[i] && !done[cur])
				done[cur] = done[i] = 1, ans ++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	F0R(i,n-1) {
		int a,b; cin >> a >> b;
		adj[a].pb(b), adj[b].pb(a);
	}
	dfs(0,1);
	cout << ans;
}
