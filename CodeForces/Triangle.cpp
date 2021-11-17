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
    #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif

    int a,b,c,d;

    while (cin >> a >> b >> c >> d)
    {
        if ((a < b+c && b < a+c && c < a+b) || (a < b+d && b < a+d && d < a+b) || (a < d+c && d < a+c && c < a+d) || (d < b+c && b < d+c && c < d+b))
            cout << "TRIANGLE" << endl;
        else if ((a == b+c || b == a+c || c == a+b) || (a == b+d || b == a+d || d == a+b) || (a == d+c || d == a+c || c == a+d) || (d == b+c || b == d+c || c == d+b))
            cout << "SEGMENT" << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
	

	return 0;
}
