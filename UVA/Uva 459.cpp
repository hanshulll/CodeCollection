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

int parent[26],rnk[26];

void Make_Set(int x){
    parent[x]=x;
    rnk[x]=0;
}

int Find(int x){
    if(x!=parent[x]) parent[x]=Find(parent[x]);
    return parent[x];
}

int Union(int &x, int &y){
    int PX=Find(x),PY=Find(y);
    if(rnk[PX]>rnk[PY])
        parent[PY]=PX;
    else{
        parent[PX]=PY;
        if(rnk[PX]==rnk[PY])
            rnk[PY]++;
    }
}
int main()
{
	FastRead
	int t;
	cin>>t;
	while(t--)
    {
        cout<<endl<<endl;
        char c;
        string s;
        cin>>s;
        ll n=s[0]-'A'+1,ans=0,x=0,y=0;
        ans=n;
        for(int i=0;i<n;i++)Make_Set(i);
        while(1){
                cin>>s;
            if(s.empty()) break;

            x=s[0]-'A'; y=s[1]-'A';

            if(Find(x)!=Find(y)){
                Union(x,y);
                ans--;
            }
        }
        if(tc!=1) printf("\n");
        printf("%d\n",ans);

    }
    return 0;

}
