 // Problem link: https://practice.geeksforgeeks.org/problems/median-of-2-sorted-arrays-of-different-sizes/1
 
 // Solution:-
 
 double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
      
        if(array1.size()>array2.size())
            return MedianOfArrays(array2,array1);
        
        int n=array1.size();
        int m=array2.size();
        
        int low=0,high=n;

        while(low<=high)
        {
            int cut1 = (low+high)>>1;
            int cut2 = (n+m+1)/2 -cut1;
            
            int l1 = cut1==0? INT_MIN : array1[cut1-1];
            int l2 = cut2==0? INT_MIN : array2[cut2-1];
            int r1 = cut1==n? INT_MAX : array1[cut1];
            int r2 = cut2==m? INT_MAX : array2[cut2];
            
            if(l1<=r2 && l2<=r1)
            {
                if((n+m)%2==0)
                    return (max(l1,l2)+min(r1,r2))/2.0;
                else
                    return max(l1,l2)/1.0;
            }
            
            else if(l1>r2)
                high=cut1-1;
            else
                low=cut1+1;
        }
        return 0.0;
    }
