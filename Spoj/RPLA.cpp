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

queue<int>S;
int count=1;
vector<vector<int> >G;
int visited[10000]={0},temp[10000];
void dfs(int u)
{
    if(visited[u])
        return;
    vector<int>::iterator i;
    visited[u]=1;
    for(i=G[u].begin();i!=G[u].end();i++)
    {
        dfs(*i);
    }
    S.push(u);
}
void display()
{
    cout<<"Scenario #"<<count<<":"<<endl<<endl;
    int count1=1;
    while(S.size()!=0)
    {
        cout<<count1++<<" "<<S.front()<<endl<<endl;
        S.pop();
    }
    count++;
}
int main()
{
    FastRead
    int t;
    cin>>t;
    while(t--)
    {
        for(int i=0;i<=9998;i++)
            visited[i]=0,temp[i]=0;
        int n,m,a,b;
        cin>>n>>m;
        G=vector<vector<int> >(n+5);
        for(int i=0;i<m;i++)
        {
            cin>>a>>b;
            temp[b]=1;
            G[a].push_back(b);
        }
        for(int i=0;i<n;i++)
            if(temp[i]==0)
                dfs(i);
        display();
    }

}