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
ll cill(ll a,ll b)
{
	if(a%b==0)
	return a/b;
	return a/b+1;
}
int main()
{
    FastRead

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int i,arr[n],risk=0,low=0,cnet=0;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]>=80 || arr[i]<=9)risk++;
            else low++;
        }
        while(0<risk)
        {
            risk-=m;
            cnet++;
        }
        while(0<low)
        {
            low-=m;
            cnet++;
        }
        cout<<cnet<<endl;
    }

}
