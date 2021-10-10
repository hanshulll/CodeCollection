class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n1 = -1, n2 = -1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i + 1] > nums[i])
                n1 = i;
        }
        if(n1 == -1)
        {reverse(nums.begin(), nums.end());
            return;}
        for(int j = n1+1; j < nums.size(); j++){
            if(nums[j] > nums[n1])
                    n2 = j;
            
            }
        swap(nums[n1], nums[n2]);
        reverse(nums.begin() + n1 + 1, nums.end());
    }
};
