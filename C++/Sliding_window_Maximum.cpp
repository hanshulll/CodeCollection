/******************************************************************************
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

https://leetcode.com/problems/sliding-window-maximum/
*******************************************************************************/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int j=0;
        int i=0;
         list<int> q;
        while(j<nums.size()){
            while(q.back()<nums[j] && q.size()>0){
                q.pop_back();
            }
            q.push_back(nums[j]);
            if(j-i+1 <k){
                j++;
            }
            else if(j-i+1==k){
                ans.push_back(q.front());
                if(nums[i]==q.front()){
                    q.pop_front();

                }
                i++;
                j++;
            }

        }
        return ans;

    }
};

};
