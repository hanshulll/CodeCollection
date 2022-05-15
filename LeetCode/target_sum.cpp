// Target Sum

/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3


Example 2:

Input: nums = [1], target = 1
Output: 1

*/




class Solution {
public:
    
    int count(vector<int>&nums, int s)
    {
        int i,j,n;
        n=nums.size();
        int t[n+1][s+1];
        
        for(i=0;i<=n;i++)
            t[i][0]=1;
        
        for(j=1;j<=s;j++)
            t[0][j]=0;
        
        for(i=1;i<=n;i++)
        {
            for(j=0;j<=s;j++)
            {
                if(nums[i-1]<=j)
                    t[i][j]=t[i-1][j]+t[i-1][j-nums[i-1]];
                else
                    t[i][j]=t[i-1][j];
            }
        
        }
        
        return t[n][s];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int s=0;
        s=accumulate(nums.begin(),nums.end(),s);
        
        if(s<target || (s+target)%2!=0)
            return 0;
        
        int s1=(s+target)/2;
        
        return count(nums,abs(s1));
        
    }
};



