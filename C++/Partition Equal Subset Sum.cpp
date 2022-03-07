class Solution {
public:
bool canPartition(vector<int>& nums){
int sum=0;

	//sum of all elemets of vector
	for(int i:nums)
        sum+=i;
	
	//check if sum is odd, partition can't be done
    if(sum&1)
        return false;
	
	//weight will become sum/2
    int target=sum/2;
	
	//initialize the lookup table
    vector<vector<bool>> dp(nums.size()+1,vector<bool>(target+1));
    
	for(int i=0;i<=nums.size();i++){
        for(int j=0;j<=target;j++){
		
		//no of elemets is 0 and weight is 0 then result is true
            if(i==0 && j==0 ){
                dp[i][j]=true;
            }
			
			//if weight is 0 then result will always be true
            else if (j==0 && i!=0)
                dp[i][j]=true;
			
			// if no of elements is 0 and weight is not 0 then result will always be false
            else if(i==0 && j!=0)
                dp[i][j]=false;
			
			// if number of elemets is less than or equal to the weight
            else if(nums[i-1]<=j){
			
			//either we include the item or exclude the item
                dp[i][j]=(dp[i-1][j-nums[i-1]] || dp[i-1][j]);
            }
			
			//else we simply exclude the item
            else{
               dp[i][j]=dp[i-1][j];
            }
        }
    }
	
	// result
    return dp[nums.size()][target];
}
};
