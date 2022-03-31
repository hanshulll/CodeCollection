class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> v;
        int cs = nums[0];
        v.push_back(cs);
        for(int i=1;i<nums.size();i++){
            cs+=nums[i];
            v.push_back(cs);
        }
        return v;
    }
};