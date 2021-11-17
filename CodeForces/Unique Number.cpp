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

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n>45)
            cout << -1 << '\n';
        else
        {
            vector<int>v;
            for(int i=9; i>=1; i--)
            {
                if(n-i<=0)
                {
                    v.push_back(n);
                    break;
                }
                else
                {
                    v.push_back(i);
                    n -= i;
                }
            }
            sort(v.begin(), v.end());
            for(auto u:v)
                cout << u ;
            cout << '\n';
        }
    }
    return 0;
}

