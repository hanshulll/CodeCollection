class Solution {
public:
    // There's a typical DP solution with O(N^2) Time and O(N) space 
    // DP[i] means the result ends at i
    // So for dp[i], dp[i] is max(dp[j]+1), for all j < i and nums[j] < nums[i]
    int lengthOfLIS(vector<int>& nums) {
        const int size = nums.size();
        if (size == 0) { return 0; } 
        vector<int> dp(size, 1);
        int res = 1;
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            res = max (res, dp[i]);
        }
        return res;
    }
};
