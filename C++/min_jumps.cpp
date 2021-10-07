#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums)
{
    int n=nums.size();
    
    if(n<=1)
        return 0;
    
    int ans=0,maxjump=nums[0], i=0, ind=0;
    if(nums[0] >= n-1)
        return 1;
    
    while(i<n-1)
    {
        if(i+nums[i] >= n-1)
        {
            ans++;
            break;
        }
        
        for(int j=i+1;j<=nums[i]+i;j++)
        {
            if(maxjump < nums[j]+j)
            {
                ind=j;
                maxjump=max(maxjump, nums[j]+j);
            }
        } 
        
        ans++;
        i=ind;
    }
    
    return ans;
}

int main()
{
   int n;
   cin>>n;

   vector<int> nums;
   for(int i=0;i<n;i++)
   {
      int x;
      cin>>x;
      nums.push_back(x);
   }

   cout<<jump(nums);
   return 0;
}