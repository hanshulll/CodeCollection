class Solution {
    public void moveZeroes(int[] nums) {
    int maxNonZero=0;
    for(int curr=0;curr<nums.length;curr++)
    {
        if(nums[curr]!=0)
        {
            swap(nums,curr,maxNonZero++);
        }
    }
    }
        
      public  void swap(int[] arr,int i, int j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    
    
}