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
#define ARRAY_SIZE(arr)       sizeof(arr)/sizeof(arr[0])
#define INT_MIN               -2147483647
#define INT_MAX               2147483647
#define INF                   2000000000
#define INF_LL                9223372036854775807LL
#define PI                    acos(-1.0)
#define llu long long unsigned
#define ll long long int
#define ld long int
#define iter(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define REP(p,a,b) for(int p=a;p<b;p++)
#define mod 1000000007
#define pob(f) pop_back(f)
#define pf(f) push_front(f)
#define pof(f) pop_front(f)
#define mkp(a,b) make_pair(a,b)
#define fst first
#define snd second
#define pii pair<int,int>
#define ins(a) insert(a)
#define   LCM(LCM_X,LCM_Y)    (LCM_X/__gcd(LCM_X,LCM_Y))*LCM_Y
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int MOD = (int)1e9+7;
const int MAX = 1e6;
char a[51][51];

static int x[]={0,1,1,1,0,-1,-1,-1};
static int y[]={1,1,0,-1,-1,-1,0,1};

int exist[51][51];
int ans[51][51];
map< pii ,int> vis;

int dfs(int i,int j,int r, int c)
{
    vis[mkp(i,j)]++;
    if(exist[i][j]!=-1) return ans[i][j];
    int temp=0;
    for(int l=0;l<8;l++)
    {
        if(i+x[l]>=0 && j+y[l]>=0 && i+x[l]<r && j+y[l]<c)
        {
            if(((char)(a[i][j]+1)==a[i+x[l]][j+y[l]])&&(vis[mkp(i+x[l],j+y[l])]<8))
            {
                temp=max(temp,dfs(i+x[l],j+y[l],r,c));
            }
        }
    }
    exist[i][j]=1;
    ans[i][j]=temp+1;
    return temp+1;
}

int main() {
    FastRead
    int r,c,t=0,ans;
    while(1)
    {
        cin>>r>>c;
        if(r==0&&c==0) break;
        t++;
        memset(exist,-1,sizeof(exist[0][0])*51*51);
        vis.clear();
        REP(i,0,r)
            cin>>a[i];
        ans=0;
        REP(i,0,r)
            REP(j,0,c)
                if(a[i][j]=='A')
                    ans=max(ans,dfs(i,j,r,c));
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
    return 0;
}

