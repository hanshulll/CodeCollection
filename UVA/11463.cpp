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
const int MAX = 1e7;
int main()
{
    FastRead

	int t,cnet=0;
	cin>>t;
	while(t--)
	{
	    ll n,m,i,j,k;
	    cin>>n>>m;
	    vector<vector<int> >adj(n,vector<int>(n,MAX));
	    for(i=0;i<n;i++)adj[i][i]=0;
	    while(m--)
        {
            ll u,v;
            cin>>u>>v;
            adj[u][v]=1;
            adj[v][u]=1;
        }
        for(k=0;k<n;k++)
        {
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        ll s,e;
        cin>>s>>e;
        int ans=0;
        for(i=0;i<n;i++)
        {
            if(adj[s][i]!=MAX && adj[i][e]!=MAX)
            {
                ans=max(ans,adj[s][i]+adj[i][e]);
            }
        }
        cout<<"Case "<<++cnet<<": "<<ans<<endl;

	}

	return 0;
}

