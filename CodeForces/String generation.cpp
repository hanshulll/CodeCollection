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
const int MAX = 1e6;
int main()
{
    FastRead
    for(int test = 1; ; test++)
    {
        int n;
        cin>>n;
        if(n == 0)
            return 0;
        map<string, int> m;
        string s, source, dest;
        for(int i = 0 ; i < n ; i++)
        {
            cin>>s;
            m[s] = i;
        }
        int table;
        cin>>table;
        double dist[50][50], cost ;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                dist[i][j] = 0.0;
            }
        }
        for(int i = 0 ; i < table ; i++)
        {
            cin>>source>>cost>>dest;
            int x, y;
            x = m[source];
            y = m[dest];
            dist[x][y] = cost;
        }
        //floyd warshall
        for(int k = 0 ; k < n ; k++)
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                    dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j]);
        int flag = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(dist[i][i] > 1.0 )
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            cout<<"Case "<<test<<": Yes\n";
        else
            cout<<"Case "<<test<<": No\n";
    }

}
