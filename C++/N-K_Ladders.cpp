
/*

Given N staircases. Find the number of ways to climb the stairs if we can take atmost K steps.
N=number of stairs
K=number of steps

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


/************************top-bottom approach****************************************************/

//lets assume n <=1000
int dp[1001] = {0};
int topstaircase( int n, int k ) {

    if (n == 0) return 1;

    if (dp[n] != 0 )
        return dp[n];

    int ans = 0;

    //for every stair check ways for prev k stairs and store them in dp
    for (int i = 1; i <= k; i++) {
        if (n - i > 0) {
            dp[n - i] = topstaircase(n - i, k);
            ans += dp[n - i];
        }

    }

    return ans;

}

// time: O(n*k)
// space: O(n)
/***********************************************************************************************/


//bottom to up approach

int bottomstaircase(int n, int k) {

    int dp[n + 1] = {0};
    dp[0] = 1;
    int sumwindow = 1;
    int start = 0, end = 0;

    for (int i = 1; i <= n; i++) {

        dp[i] = sumwindow;

        sumwindow += dp[i];
        end++;

        //if window size is greater than k remove first element
        if (end - start + 1 > k) {
            sumwindow -= dp[start];
            start++;
        }

    }

    return dp[n];


}

//time O(n)
//space O(n)


/**************************************************************************/

int main() {
    checkjudge();

    int n, k;
    cin >> n >> k;

    cout << bottomstaircase(3, 3);

    return 0;
}