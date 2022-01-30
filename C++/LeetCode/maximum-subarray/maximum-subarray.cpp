class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ms = INT_MIN, minSum = 0, cs = 0;
        for(int i=0;i<nums.size();i++){
            cs += nums[i];
            ms = max(ms, cs-minSum);
            minSum = min(minSum, cs);
        }
        return ms;
    }
};