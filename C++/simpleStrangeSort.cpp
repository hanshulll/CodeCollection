/*****************************
 A. Simply Strange Sort 
time limit per test2 seconds
memory limit per test512 megabytes

You have a permutation: an array a=[a1,a2,…,an] of distinct integers from 1 to n. The length of the permutation n is odd.

Consider the following algorithm of sorting the permutation in increasing order.

A helper procedure of the algorithm, f(i), takes a single argument i (1≤i≤n−1) and does the following. If ai>ai+1, the values of ai and ai+1 are exchanged. Otherwise, the permutation doesn't change.

The algorithm consists of iterations, numbered with consecutive integers starting with 1. On the i-th iteration, the algorithm does the following:

if i is odd, call f(1),f(3),…,f(n−2);
if i is even, call f(2),f(4),…,f(n−1).
It can be proven that after a finite number of iterations the permutation will be sorted in increasing order.

After how many iterations will this happen for the first time?

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). Description of the test cases follows.

The first line of each test case contains a single integer n (3≤n≤999; n is odd) — the length of the permutation.

The second line contains n distinct integers a1,a2,…,an (1≤ai≤n) — the permutation itself.

It is guaranteed that the sum of n over all test cases does not exceed 999.

Output
For each test case print the number of iterations after which the permutation will become sorted in increasing order for the first time.

If the given permutation is already sorted, print 0.


Sample input
3
3
3 2 1
7
4 5 7 1 3 2 6
5
1 2 3 4 5

Sample output
3
5
0
***************************/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define vi vector<int>
#define vvi vector<vi>
#define ppi pair<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

typedef long long ll;

/*********************************/

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi v(n);
        rep(i, 0, n)
        {
            cin >> v[i];
        }
        vi v1(n);
        iota(all(v1), 1);

        int count = 0;
        int i = 1;
        while (1)
        {
            if (v == v1)
            {
                break;
            }

            if (i % 2 != 0)
            {
                for (int j = 0; j < n - 1; j += 2)
                {
                    if (v[j] > v[j + 1])
                    {
                        int temp = v[j];
                        v[j] = v[j + 1];
                        v[j + 1] = temp;
                    }
                }
            }
            else
            {
                for (int j = 1; j < n - 1; j += 2)
                {
                    if (v[j] > v[j + 1])
                    {
                        int temp = v[j];
                        v[j] = v[j + 1];
                        v[j + 1] = temp;
                    }
                }
            }
            count++;
            i++;
        }

        cout << count << endl;
    }

    return 0;
}