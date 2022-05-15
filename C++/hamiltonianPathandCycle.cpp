#include <iostream>
#include <vector>
#include<string>
using namespace std;

class Edge
{
public:
    int v = 0;
    int w = 0;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

const int N = 7;
vector<vector<Edge>> graph(N);

void addEdge(int u, int v, int w)
{
    graph[u].push_back(Edge(v, w));
    graph[v].push_back(Edge(u, w));
}

int findEdge(int u, int v)
{
    int idx = -1;
    for (int i = 0; i < graph[u].size(); i++)
    {
        if (graph[u][i].v == v)
        {
            idx = i;
            break;
        }
    }

    return idx;
}


void constructGraph(){
   
    addEdge(0,1,10);
    addEdge(0,3,10);
    addEdge(1,2,10);
    addEdge(2,3,40);
    addEdge(3,4,2);
    addEdge(4,5,2);
    addEdge(4,6,8);
    addEdge(5,6,3);
    addEdge(7, 2, 3);
    addEdge(6, 2, 3);
    addEdge(6, 7, 3);
}


int hamintonialPathAndCycle(int src, int osrc, int totalNoEdges, vector<bool> &vis, string psf)
{
    if (totalNoEdges == N - 1)
    {
        int idx = findEdge(osrc, src);
        if (idx != -1)
            cout << "Cycle : " + psf + to_string(src);
        else
            cout << "Path : " + psf + to_string(src);
        cout << endl;
        return 1;
    }

    vis[src] = true;
    int count = 0;
    for (Edge e : graph[src])
    {
        if (!vis[e.v])
            count += hamintonialPathAndCycle(e.v, osrc, totalNoEdges + 1, vis, psf + to_string(src) + " ");
    }

    vis[src] = false;
    return count;
}

int hamintonialPathAndCycle(int src)
{
    vector<bool> vis(N, false);
    cout << hamintonialPathAndCycle(src, src, 0, vis, "") << endl;
}


int main()
{

     hamintonialPathAndCycle(0);
    
    return 0;
}