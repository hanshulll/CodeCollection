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
    int t;
    cin>>t;
    while(t--)
    {
        ll n,sum=0,i;
        cin>>n;
        ll arr[n];
        for(i=0; i<n; i++)
        {

            cin>>arr[i];
            sum+=arr[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
