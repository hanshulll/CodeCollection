#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
const int INF = 1e8 + 5;
int n,m,u[N],v[N],w[N],d[N];

int main()
{
    while(cin>>n>>m && n+m)
    {
        for(int i=0; i<m; ++i)
        {
            cin>>u[i+i]>>v[i+i]>>w[i+i];
            u[i+i+1]=v[i+i],v[i+i+1]=u[i+i],w[i+i+1]=-w[i+i];
        }
        m+=m,d[0]=0;
        for(int i=1;i<n;i++)
        {
            d[i]=INF;
        }
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                d[v[j]]=min(d[v[j]],d[u[j]]+w[j]);
            }

        }
        int yes=0;
        for(int j=0;j<m;++j)
        {
            if(d[v[j]]>d[u[j]]+w[j])
            {
                yes=1;
                break;
            }

        }
        puts(yes ? "Y":"N");
    }
    return 0;

}
