#include<bits/stdc++.h>

using namespace std;

struct pt
{
    int x, y;
    pt(int a, int b)
    { x = a, y = b; }
} ;

int N, x[100], y[100], indx[100];
set<pair<int, int> > points; // keeps track of which (x, y) coordinates are farms
vector<pt> nodes;
vector<int> adj[500]; // adjacency list

// Returns the taxicab distance between nodes[a] and nodes[b].
int length(int a, int b)
{
    return abs(nodes[a].x - nodes[b].x) + abs(nodes[a].y - nodes[b].y);
}

// Returns whether the first point (x1, y1) is on the segment (x2, y2) -> (x3, y3).
bool in_segment(int x1, int y1, int x2, int y2, int x3, int y3)
{
    if(x2 == x3)
        return x1 == x2 && y1 > min(y2, y3) && y1 < max(y2, y3);
    else if(y2 == y3)
        return y1 == y2 && x1 > min(x2, x3) && x1 < max(x2, x3);
    else // invalid
        return true;
}

// Returns whether a right-angle path from nodes[a] to nodes[b] is possible (does not intersect any of the N original points, except potentially at endpoints).
bool possible(int a, int b)
{
    // Method 1: travel vertical first, then horizontal
    bool good1 = nodes[a].x == nodes[b].x || nodes[a].y == nodes[b].y || points.find(make_pair(nodes[a].x, nodes[b].y)) == points.end();
    for(int i = 0; i < N; i++)
        if(in_segment(x[i], y[i], nodes[a].x, nodes[a].y, nodes[a].x, nodes[b].y) || in_segment(x[i], y[i], nodes[a].x, nodes[b].y, nodes[b].x, nodes[b].y))
        {
            good1 = false;
            break;
        }
    if(good1)
        return true;

    //Method 2: travel horizontal first, then vertical
    bool good2 = nodes[a].x == nodes[b].x || nodes[a].y == nodes[b].y || points.find(make_pair(nodes[b].x, nodes[a].y)) == points.end();
    for(int i = 0; i < N; i++)
        if(in_segment(x[i], y[i], nodes[a].x, nodes[a].y, nodes[b].x, nodes[a].y) || in_segment(x[i], y[i], nodes[b].x, nodes[a].y, nodes[b].x, nodes[b].y))
        {
            good2 = false;
            break;
        }
    if(good2)
        return true;

    return false;
}

// Returns the length of the shortest path from nodes[a] to nodes[b].
bool vis[500];
int dist[500], infinity = 1023456789;
int dijkstra(int a, int b)
{
    for(int i = 0; i < nodes.size(); i++)
    {
        dist[i] = infinity;
        vis[i] = false;
    }
    // Don't visit farms (except for the start and end locations).
    for(int i = 0; i < N; i++)
        if(indx[i] != a && indx[i] != b)
            vis[indx[i]] = true;

    dist[a] = 0;
    for(int i = 0; i < nodes.size(); i++)
    {
        int next = 0;
        for(int j = 0; j < nodes.size(); j++)
            if(!vis[j] && (dist[j] < dist[next] || vis[next]))
                next = j;
        if(vis[next] || dist[next] == infinity)
            return -1;
        if(next == b)
            return dist[next];
        vis[next] = true;
        for(int j = 0; j < adj[next].size(); j++)
            if(!vis[adj[next][j]])
                dist[adj[next][j]] = min(dist[adj[next][j]], dist[next] + length(next, adj[next][j]));
    }
    return -1;
}

int main()
{
    FILE * w = fopen("delivery.in", "r");
    FILE * o = fopen("delivery.out", "w");

    fscanf(w, "%d", &N);
    for(int i = 0; i < N; i++)
    {
        fscanf(w, "%d %d", &x[i], &y[i]);
        points.insert(make_pair(x[i], y[i]));
    }

    // Make nodes
    for(int i = 0; i < N; i++)
        for(int a = -1; a <= 1; a++)
            for(int b = -1; b <= 1; b++)
            {
                if(a == 0 && b == 0)
                {
                    nodes.push_back(pt(x[i], y[i]));
                    indx[i] = nodes.size() - 1;
                }
                else if(a * b == 0 && points.find(make_pair(x[i] + a, y[i] + b)) == points.end())
                    nodes.push_back(pt(x[i] + a, y[i] + b));
            }

    // Make edges
    for(int i = 0; i < nodes.size(); i++)
        for(int j = i + 1; j < nodes.size(); j++)
            if(possible(i, j))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }

    // Dijkstra's Algorithm
    int answer = 0;
    for(int i = 0; i < N; i++)
    {
        int next = dijkstra(indx[i], indx[(i + 1) % N]);
        if(next < 0)
        {
            answer = -1;
            break;
        }
        else
            answer += next;
    }

    fprintf(o, "%d\n", answer);
    printf("%d\n", answer);

    return 0;
}