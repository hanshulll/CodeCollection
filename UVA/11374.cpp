#include <bits/stdc++.h>
using namespace std;
const int MAXN = 550;
const int MAXM = 550;
const int INF = 0x3f3f3f3f;
struct Edge{
	int from,to,dist;
	Edge(int u,int v,int d):from(u),to(v),dist(d){} 
}; 
struct HeapNode{ 
	int d,u;
	bool operator < (const HeapNode& rhs) const{
		return d > rhs.d;
	}
};
struct Dijkstra{
	int n,m;
	vector<Edge> edges;
	vector<int> G[MAXN];
	bool done[MAXN];   
	int d[MAXN];     
	int p[MAXN];      
	void init(int n){ 
		this -> n = n;
		for(int i = 0; i <= n; i++){
			G[i].clear();
		}
		edges.clear();
	}
	void AddEdge(int from,int to,int dist){
		edges.push_back(Edge(from,to,dist));
		m = edges.size();
		G[from].push_back(m - 1);
	}
	void dijkstra(int s){
		priority_queue<HeapNode> Q;
		for(int i = 0; i <= n; i++){
			d[i] = INF;
		}
		d[s] = 0;
		memset(done,0,sizeof(done));
		Q.push((HeapNode){0,s});
		while(!Q.empty()){
			HeapNode x = Q.top();
			Q.pop();
			int u = x.u;
			if(done[u]){
				continue;
			}
			done[u] = true;
			for(int i = 0; i < G[u].size(); i++){
				Edge& e = edges[G[u][i]];
				if(d[e.to] > d[u] + e.dist){
					d[e.to] = d[u] + e.dist;
				    p[e.to] = u; 
					Q.push((HeapNode){d[e.to],e.to});
				}
			}
		}
	}
}dij;
int d1[MAXN],d2[MAXN];
int pre1[MAXN],pre2[MAXN];
int main(void)
{
	int n,m,s,e,x,y,z,k,cur;
	int anss,ss,ee;
	int kase = 0;
	while(scanf("%d %d %d",&n,&s,&e) != EOF) {
		scanf("%d",&m);
		dij.init(n);
		for(int i = 1; i <= m; i++) {
			scanf("%d %d %d",&x,&y,&z);
			dij.AddEdge(x,y,z);
			dij.AddEdge(y,x,z);
		}
		dij.dijkstra(s);
		for(int i = 1; i <= n; i++) {
			d1[i] = dij.d[i];
			pre1[i] = dij.p[i];
		}
		dij.dijkstra(e);
		for(int i = 1; i <= n; i++) {
			d2[i] = dij.d[i];
			pre2[i] = dij.p[i];
		}
		scanf("%d",&k);
		ss = ee = 0;
		anss = d1[e];
		for(int i = 1; i <= k; i++) {
			scanf("%d %d %d",&x,&y,&z);
			if(anss > d1[x] + d2[y] + z) {
				anss = d1[x] + d2[y] + z;
				ss = x,ee = y; 
			}
			if(anss > d1[y] + d2[x] + z) {
				anss = d1[y] + d2[x] + z;
				ss = y,ee = x;
			}
		} 
		if(kase) printf("\n");
		else kase++;
		vector<int> ans;
		if(ss) {
			cur = ss;
			while(cur != s) {
				ans.push_back(cur);
				cur = pre1[cur];
			} 
			ans.push_back(cur);
			for(int i = ans.size() - 1; i >= 0; i--) {
				if(i != ans.size() - 1) printf(" ");
				printf("%d",ans[i]);
			}
			cur = ee;
			ans.clear();
			while(cur != e) {
				ans.push_back(cur);
				cur = pre2[cur];
			}
			ans.push_back(cur);
			printf(" ");
			for(int i = 0 ; i <= ans.size() - 1; i++) {
				if(i != 0) printf(" ");
				printf("%d",ans[i]);
			}
			printf("\n%d\n",ss);
		}
		else {
			ans.clear();
			cur = e;
			while(cur != s) {
				ans.push_back(cur);
				cur = pre1[cur];
			} 
			ans.push_back(cur);
			for(int i = ans.size() - 1; i >= 0; i--) {
				if(i != ans.size() - 1) printf(" ");
				printf("%d",ans[i]);
			}
			printf("\nTicket Not Used\n");
		}
		printf("%d\n",anss);
	}
	return 0;
}
