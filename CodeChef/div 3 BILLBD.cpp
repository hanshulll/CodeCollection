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
const N = 109;
string A[N], B[N];
int main()
{
	FastRead
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> B[i];
	}

	int ans = 0, max = n * m / 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (A[i][j] != B[i][j])ans++;
		}
	}
	if (ans > max)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (A[i][j] == B[i][j])
				{
					if (A[i][j] == 'X')
					{
						cout << ".";
					}
					else cout << "X";
				}
				else cout<<A[i][j];

			}
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if(A[i][j]!=B[i][j])
				{
					cout<<A[i][j];
				}
				else cout<<B[i][j];
			}
			cout << endl;
		}

	}
	return 0;

}
