//
//  LongestIncreasingPath.cpp
//  Question :: --
//Given a two-dimensional integer matrix, find the length of the longest strictly increasing path. You can move up, down, left, or right.
//
//Constraints
//
//n, m ≤ 500 where n and m are the number of rows and columns in matrix
//Example 1
//Input
//matrix = [
//    [1, 3, 5],
//    [0, 4, 6],
//    [2, 2, 9]
//]
//Output
//6
//Explanation
//The longest path is [0, 1, 3, 5, 6, 9]


//Intuition
//Do a dfs exploration with all neighbours strictly greater than current value. While exploring such locations, cache the intermediate results in a table. Since the condition to explore neighbours is that of strictly increasing, there is no need to maintain a visited table.
//
//Implementation
//Initialize a 'dp' table with values -1 of size row * column, same as that of input matrix.
//Now for all values -1, explore those locations in all 4 directions keeping in mind the constraint of strictly increasing. Keep storing the best answer in a variable. The max of all such explorations will be the maximum strictly increasing path.
//
//Time Complexity
//A constant amount of operations are done per matrix cell location. So for a matrix of size n*n, time complexity is O(n^2)
//
//Space Complexity
//A dp table of size equal to matrix is used. Therefore space complexity is O(n^2)


//  Created by Arihant Thriwe on 02/10/21.
//

const int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
int dfs(const vector<vector<int>> &matrix, vector<vector<int>> &dp, const int &r, const int &c) {
    if (dp[r][c] != -1) return dp[r][c];
    dp[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int nextR = r + dir[i][0];
        int nextC = c + dir[i][1];
        if (nextR < 0 || nextC < 0 || nextR >= matrix.size() || nextC >= matrix[0].size() ||
            matrix[nextR][nextC] <= matrix[r][c]) {
            continue;
        }
        dp[r][c] = max(dp[r][c], 1 + dfs(matrix, dp, nextR, nextC));
    }
    return dp[r][c];
}
int solve(vector<vector<int>> &matrix) {
    int m = matrix.size();
    if (m < 1) return 0;
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == -1) dfs(matrix, dp, i, j);
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}
