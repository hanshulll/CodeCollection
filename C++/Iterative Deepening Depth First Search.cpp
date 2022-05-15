#include<list>
#include<iostream>
using namespace std;


class Graph
{
	int V;
	list<int> *adj;

    public:

	bool DLS(int src, int target, int limit){
        if (src == target)
            return true;

        // If reached the maximum depth, stop recursing.
        if (limit <= 0)
		return false;

        for (auto i = adj[src].begin(); i != adj[src].end(); ++i)
            if (DLS(*i, target, limit-1) == true)
                return true;

        return false;
    }

	Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }

	void addEdge(int v, int w){
        adj[v].push_back(w); // Add w to v’s list.
    }

	bool IDDFS(int src, int target, int max_depth){    // Repeatedly depth-limit search till the maximum depth.
        for (int i = 0; i <= max_depth; i++){
            if (DLS(src, target, i) == true)
                return true;
        }
        return false;
    }
};




int main()
{
	Graph g(10);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 5);
	g.addEdge(1, 8);
	g.addEdge(2, 9);
	g.addEdge(5, 16);
	g.addEdge(5, 5);
	g.addEdge(8, 2);

	int target = 16, limit = 3, src = 0;
    if (g.IDDFS(src, target, limit) == true)
		cout << "Target reached within Maxdepth: "<< limit << endl;
	else
		cout << "Target cannot be reached within Maxdepth: "<< limit << endl;
	return 0;
}
