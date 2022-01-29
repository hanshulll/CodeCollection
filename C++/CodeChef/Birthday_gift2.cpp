#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int cost_of_gifts[n];
        for (int i = 0; i < n; i++)
        {
            cin >> cost_of_gifts[i];
        }
        sort(cost_of_gifts, cost_of_gifts + n, greater<int>());//sorting the array in descending order
        long long int chef1 = 0, chef2 = 0;
        for (int i = 0; i < 2 * k; i++)
        {
            if (i == 2 * k - 1)
            {
                chef2 += cost_of_gifts[i] + cost_of_gifts[i + 1]; //adding cost of 2 gifts for the person who chooses in second chance
            }
            else if (i == 1 || (i >= 3 && i % 2 != 0))
            {

                chef2 += cost_of_gifts[i]; //adding cost of gifts in odd positions
            }
            else
            {
                chef1 += cost_of_gifts[i];//adding cost of gifts in even positions
            }
        }
        cout << max(chef1, chef2) << endl;//maximum of results obtained above
    }
}