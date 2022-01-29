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
const int MOD = (int)1e9 + 7;
const int MAX = 1e6;
int main()
{
	FastRead
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	double x1, y1, x2, y2, x3, y3;
	double a, b, c, S, R;

	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
		a = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		b = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
		c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));

		S = 0.5 * fabs(x1 * y2 + x2 * y3 + x3 * y1 - y1 * x2 - y2 * x3 - y3 * x1);

		R = a * b * c / (4 * S);

		cout << fixed << setprecision(2) << 2 * pi*R << endl;
	}


	return 0;
}
