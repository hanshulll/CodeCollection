#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef long long unsigned llu;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (auto &i : vec)
        cin >> i;

    int zeroesCnt = 0, i = 0, ans = 0;
    for (int j = 0; j < vec.size(); j++)
    {
        if (vec[j] == 0)
            zeroesCnt++;

        while (zeroesCnt > k)
        {
            if (vec[i] == 0)
                zeroesCnt--;
            i++;
        }

        // zerosCnt <=k
        ans = max(ans, j - i + 1);
    }

    cout << ans << endl;
    return 0;
}