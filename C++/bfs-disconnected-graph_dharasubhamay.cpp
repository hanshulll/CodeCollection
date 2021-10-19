// C++ implementation of modified BFS

#include<bits/stdc++.h>
using namespace std;


// undirected graph.
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}


void BFSUtil(int u, vector<int> adj[],
			vector<bool> &visited)
{

	
	list<int> q;

	
	visited[u] = true;
	q.push_back(u);

	

	while(!q.empty())
	{
		
		u = q.front();
		cout << u << " ";
		q.pop_front();

		
		for (int i = 0; i != adj[u].size(); ++i)
		{
			if (!visited[adj[u][i]])
			{
				visited[adj[u][i]] = true;
				q.push_back(adj[u][i]);
			}
		}
	}
}


void BFS(vector<int> adj[], int V)
{
	vector<bool> visited(V, false);
	for (int u=0; u<V; u++)
		if (visited[u] == false)
			BFSUtil(u, adj, visited);
}


int main()
{
	int V = 5;
	vector<int> adj[V];

	addEdge(adj, 0, 4);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	addEdge(adj, 1, 4);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 4);
	BFS(adj, V);
	return 0;
}
