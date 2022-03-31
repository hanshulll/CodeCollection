// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long rightmax, leftmax, low=0, high=n-1;
        leftmax=rightmax=INT_MIN;
        long long result=0;
        while(low<=high){
            if(arr[low]<arr[high]){
                if(arr[low]>leftmax){
                    leftmax = arr[low];
                }
                else{
                    result+=leftmax-arr[low];
                }
                low++;
            }
            else{
                if(arr[high]>rightmax){
                    rightmax = arr[high];
                }
                else{
                    result+=rightmax-arr[high];
                }
                high--;
            }
        }
        return result;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends