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
int main ()
{
	FastRead
	int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
	int n;
	int res[25];
	while (cin >> n) {
		if (n == 0) break;

		memset(res, 0, sizeof(int) * 25);

		for (int i = 2; i <= n; i++) {
			int temp = i;
			for (int j = 0; j < 25; j++) {
				if (primes[j] > i) break;
				while (temp % primes[j] == 0) {
					temp /= primes[j];
					res[j]++;
				}
			}
		}
		int max = 0;
		for (int i = 0; i < 25; i++) {
			if (res[i] > 0) max = i;
		}
		cout << setw(3) << n << "! =";
		for (int i = 0; i <= max; i++) {
			if (i > 0 && i % 15 == 0) cout << endl << "      ";
			cout << setw(3) << res[i];
		}
		cout << endl;
	}
	return 0;
}

