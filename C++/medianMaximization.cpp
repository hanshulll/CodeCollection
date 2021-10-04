/*************************
A. Median Maximization
time limit per test1 second
memory limit per test256 megabytes

You are given two positive integers n and s. Find the maximum possible median of an array of n non-negative integers (not necessarily distinct), such that the sum of its elements is equal to s.

A median of an array of integers of length m is the number standing on the ⌈m2⌉-th (rounding up) position in the non-decreasing ordering of its elements. Positions are numbered starting from 1. For example, a median of the array [20,40,20,50,50,30] is the ⌈m2⌉-th element of [20,20,30,40,50,50], so it is 30. There exist other definitions of the median, but in this problem we use the described definition.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. Description of the test cases follows.

Each test case contains a single line with two integers n and s (1≤n,s≤109) — the length of the array and the required sum of the elements.

Output
For each test case print a single integer — the maximum possible median.

Sample Input
8
1 5
2 5
3 5
2 1
7 17
4 14
1 1000000000
1000000000 1

Sample output
5
2
2
0
4
4
1000000000
0


*****************/
#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define nline '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define set_bits __builtin_popcountll
#define sz(v) ((int)((v).size()))
#define rep(i, a, b) for (int i = a; i < b; i++)
#define all(v) ((v).begin()), ((v).end())
#define allr(w) ((w).rbegin()), ((w).rend())

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;

/*********************************/

bool isPowOfTwo(int x)
{
    return x && (!(x & (x - 1)));
}

bool cmp1(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.first < b.first);
}

bool cmp2(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

ll min3(ll a, ll b, ll c)
{
    return min(a, min(b, c));
}

ll min4(ll a, ll b, ll c, ll d)
{
    return min(a, min(b, min(b, c)));
}

ll max3(ll a, ll b, ll c)
{
    return max(a, max(b, c));
}

ll max4(ll a, ll b, ll c, ll d)
{
    return max(a, max(b, max(b, c)));
}

/*********************************/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, s;
        cin >> n >> s;

        if (n == 1)
            cout << s << endl;
        else if (s == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            int x;
            if (n % 2 == 0)
                x = (s / (n / 2 + 1));
            else
            {
                x = (s / round(n / (2 * 1.0)));
            }
            cout << x << endl;
        }
    }
    return 0;
}