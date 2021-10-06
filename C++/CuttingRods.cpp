



/*
Given a rod of length 'N' and profit for each piece of length of rod. Find max profit that
can be generated.
N=8
length | 1  2  3  4  5  6   7   8
price  | 1  5  8  9  10 17  17  20
output: 22
N=8
length | 1  2  3  4  5  6   7   8
price  | 3  5  8  9  10 17  17  20
output: 24

*/





#include<bits/stdc++.h>
#define ll long int
#define pb push_back


using namespace std;

void checkjudge() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt" , "w" , stdout);
#endif
}




/***********************   TOP DOWN APPROACH  ***************************************************/
int dp[1000] = {0};
int maxProfit(vector<int> piece, vector<int> cost, int n) {

    //base condition
    if (n == 0)
        return 0;
    if ( dp[n] != 0)
        return dp[n];


    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (n - piece[i] >= 0) {
            int temp = dp[n - piece[i]] = maxProfit(piece, cost, n - piece[i]);
            temp += cost[i];

            if (temp > ans)
                ans = temp;
        }
    }

    return ans;

}

/* Time: O(n*n) Space: O(n) */

/********************* BOTTOM UP APPROACH**********************************************/

int maxProfit2(vector<int> piece, vector<int> cost, int n) {

    int dp[n + 1] = {0};

    for (int i = 1; i < n + 1; i++) {
        int ans = INT_MIN;

        for (int j = 0; j < n; j++) {
            if ( i - piece[j] >= 0   ) {
                int temp = dp[i - piece[j]] + cost[j];
                if (temp > ans)
                    ans = temp;
            }
        }
        dp[i] = ans;
    }
    return dp[n];
}

/* Time : O(n*n) Space : O(n) */

int main() {
    checkjudge();

    int n;
    cin >> n;

    vector<int> piece(n), cost(n);

    for (int i = 0; i < n; i++)
        cin >> piece[i];

    for (int i = 0; i < n; i++)
        cin >> cost[i];

    cout << maxProfit2(piece, cost, n);
    cout << endl << maxProfit(piece, cost, n);

    return 0;
}