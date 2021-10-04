/******************************************************************************
Given an integer array nums, return the length of the longest strictly increasing subsequence.

question link-https://leetcode.com/problems/longest-increasing-subsequence/

Time complexity of this method o(NlogN)
*******************************************************************************/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

         if (nums.size() == 0)
        return nums.size();

    vector<int>::iterator m = nums.begin();  // m will mark the virtual "S.end()".
    for (int& val : nums) {
        auto it = lower_bound(nums.begin(), m, val);
        *it = val;
        if (it == m)
            m++;
    }

    return m - nums.begin();

    }
};
