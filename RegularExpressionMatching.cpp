class Solution {
public:
bool isMatch(string str, string p) {
    int n1 = str.size();
    int n2 = p.size();
    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));

    //Initialise
    dp[n1][n2] = true;
    //Last row
    for (int c = n2 - 2; c >= 0; c--) {
        if (p[c + 1] == '*') {
            dp[n1][c] = dp[n1][c + 2];
        }
    }

    for (int r = n1 - 1; r >= 0; r--) {
        for (int c = n2 - 1; c >= 0; c--) {
            if (p[c + 1] == '*') {
                dp[r][c] = dp[r][c] || dp[r][c + 2];
                if (str[r] == p[c] || p[c] == '.')
                    dp[r][c] = dp[r][c] || dp[r + 1][c];
            } else if (str[r] == p[c] || p[c] == '.') {
                dp[r][c] = dp[r][c] || dp[r + 1][c + 1];
            }
        }
    }

    return dp[0][0];
}
};
