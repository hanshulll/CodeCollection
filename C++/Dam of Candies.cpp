// Problem link: https://practice.geeksforgeeks.org/problems/10471201e923a0b88a0c1482e6c7e8cc6fdfe93a/1

// Solution:-

int maxCandy(int height[], int n) 
    { 
        // Your code goes here
        int res=0, low=0, high=n-1;
        
        while(low<high)
        {-
            res = max(res, min(height[low], height[high]) * (high-low-1));
            
            if(height[low]<height[high]) 
                low++;
                
            else
                high--;
        }
        

        return res;
    }  
