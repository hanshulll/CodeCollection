// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        // M!
        // for(int i=0;i<n;i++){
        //     long long sum1 = 0;
        //     long long sum2 = 0;
        //     for(int j=0;j<i;j++){
        //         sum1+=a[j];
        //     }
        //     for(int j=i+1;j<n;j++){
        //         sum2+=a[j];
        //     }
        //     if(sum1 == sum2){
        //         return i+1;
        //     }
        //     else{
        //         continue;
        //     }
        // }
        // return -1;
        
        // M2
        int rightSum=0;
        for(int i=0;i<n;i++){
            rightSum += a[i];
        }
        int leftSum = 0;
        for(int i=0;i<n;i++){
            rightSum -= a[i];
            if(rightSum == leftSum){
                return i+1;
            }
            else{
                leftSum += a[i];
            }
        }
        return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends