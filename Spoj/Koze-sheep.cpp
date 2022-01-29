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

string s[251];
bool visited[251][251];
int k=0,v=0,r,c;
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
bool val(int x,int y)
{
	return (x>=0 & y>=0 &&x<r && y<c);
}
void dfs(int x,int y)
{
	if(s[x][y]!='#' && !visited[x][y])
	{
		visited[x][y]=1;
		if(s[x][y]=='k')k++;
		else if(s[x][y]=='v')v++;
		for(int i=0;i<4;i++)
		{
			int a,b;
			a = dx[i]+x;
			b = dy[i]+y;
			if(val(a,b))
			{
				dfs(a,b);
			}
		}
	}
}
int main()
{
    FastRead
    int i,j,shp=0,wlf=0;
    cin>>r>>c;
    for(i=0;i<r;i++)
    {
    	cin>>s[i];
    }
    for(i=0;i<r;i++)
    	{
    		for(j=0;j<c;j++)
    		{
    			k=0,v=0;
    			dfs(i,j);
    			if(k>v)
    			{
    				ship+=k;
    			}
    			else
    			{
    				wlf+=v;
    			}
    		}
    	}
	cout<<shp<<" "<<wlf<<endl;

	return 0;
}
