#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const int Max = 3e2 + 10;

ll dist[Max][Max];

int main()
{

    int n, k, u, v, w;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin>>dist[i][j];
        }
    }
    cin>>k;
    while(k--)
    {
        cin>>u>>v>>w;
        ll ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][u] + w + dist[v][j]);
                dist[i][j] = min(dist[i][j], dist[i][v] + w + dist[u][j]);
                if(j > i)
                {
                    ans += dist[i][j];
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
