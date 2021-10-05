// Link : https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        int sum[nums.size()+1];
        if(nums.size()<2){
            return nums[nums.size()-1];
        }
        bool flag =false;   //using flag to check if prev house was selected
        sum[0] = nums[0];
        sum[1] = max(nums[0],nums[1]);
        if(max(nums[0],nums[1])==nums[1]){
            flag = true;  // flag true because current house selected
        }
        for(int i = 2;i<nums.size();i++){
            if(flag == true){
                int m = max(sum[i-1],sum[i-2]+nums[i]); // since flag is true so sum[i-1] + nums[i] not possible because in sum[i-1] house i-1 was selected.
                if(m == sum[i-1]){
                    flag = false;  // flag false because current house not selected
                }
                sum[i] = m;
            }
            else{
                int m = max(sum[i-1]+nums[i],sum[i-2]+nums[i]);
                flag = true; // In else condition the current house will always be selected so flag false
                sum[i] = m;
                
            }
        }
        return sum[nums.size()-1];
        
    }
};
