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
#include <iostream>

using namespace std;

int mod(int a, int b, int c)
{
	if (b == 0) return 1;

	if (b % 2 == 0)
	{
		int x = mod(a, b / 2, c);
		return (x * x) % c;
	}
	else return (a % c * mod(a, b - 1, c)) % c;
}

int main() {

	FastRead

	int B, P, M;

	while (cin >> B >> P >> M)
		cout << mod(B, P, M) << endl;

	return 0;
}
