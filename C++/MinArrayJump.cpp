/*

Given an array on length N and each index contains max steps we can take forward from that index. Find min steps
to reach the end.

12
3 4 2 1 2 3 10 1 1 1 2 5

4 steps
3 -> 4 -> 10 -> 5


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
int minJumps(vector<int> arr, int n, int i = 0) {

    if (i == n - 1 )
        return 0;
    if (dp[i] != 0)
        return dp[i];

    int ans = INT_MAX;
    int j = i + 1;
    while ( j < n and j <= i + arr[i]  ) {
        int temp = dp[j] = minJumps(arr, n, j);
        temp += 1;
        if (temp < ans)
            ans = temp;
        j++;
    }

    return ans;

}


/* Time: O(n*n) Space: O(n) */

/********************* BOTTOM UP APPROACH**********************************************/

int minJumps2(vector<int> arr , int n ) {
    int dp[n] = {0};

    int i = n - 2;

    while (i >= 0) {

        int j = i + 1;
        int ans = INT_MAX;
        while (j < n and j <= i + arr[i] ) {
            if (dp[j] < ans)
                ans = dp[j];
            j++;
        }
        dp[i] = 1 + ans;

        i--;
    }

    return dp[0];

}

/* Time : O(n*n) Space : O(n) */

int main() {
    checkjudge();

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];


    cout << minJumps(arr, n) << endl;
    cout << minJumps2(arr, n);

    return 0;
}