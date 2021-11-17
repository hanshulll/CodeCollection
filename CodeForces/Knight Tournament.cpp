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
int n,m,i,l,r,x,out[300001];
int main()
{
    FastRead
    set<int> s;
    set<int>::iterator it,tmp;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        s.insert(i);
    }
    while(m--)
    {
        cin>>l>>r>>x;
        for(it=s.lower_bound(l);*it<=r&&it!=s.end();)
        {
            if(*it!=x)
            {
                out[*it]=x;
                tmp=it;
                it++;
                s.erase(tmp);
            }
            else it++;
        }
    }
    for(i=1;i<=n;i++)
    {
        cout<<out[i]<<" ";
    }
    return 0;
}
