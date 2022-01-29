#include<bits/stdc++.h>
using namespace std;
void topo(int n,vector<int>adj[])
{
     vector<int>trop;
    vector<int>indeg(n,0);
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        for(auto it:adj[i])
        {
            indeg[it]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
        }
    }
    int node;
    while(!q.empty())
    {
        node=q.front();
        q.pop();
        trop.push_back(node);
        for(auto it:adj[node])
        {
            indeg[it]--;
            if(indeg[it]==0)
            {
                q.push(it);
            }
        }
    }
    for(int i=0;i<trop.size();i++)
    {
        cout<<trop[i]<<" ";
    }
}
int main()
{
    int n,m;
    cout<<"Enter vertices";
    cin>>n;
    cout<<"Enter edges";
    cin>>m;
    vector<int>adj[n+1];
  // vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    topo(n,adj);
}
