//leetcode problem no. 33
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int mid=0;
        int right=nums.size()-1;
        
        while(left<=right)
        {
        	mid=left+(right-left)/2;
        	if(nums[mid]==target)
        	return mid;
        	
        	else if(nums[mid]>=nums[left])
        	{
        		if(target>=nums[left] && target<=nums[mid])
        		right=mid-1;
        		else
        		left=mid+1;
			}
			else
			{
				if(target>=nums[mid] && target<=nums[right])
				left=mid+1;
				else
				right=mid-1;
			}
		}
		return -1;
    }
};
