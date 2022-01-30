// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool search(int arr[], int n, int key){
	    int s = 0, e = n-1;
	    if(arr[s] == key or arr[e] == key)
	        return true;
	    while(s<=e){
	        int mid = (s+e)/2;
	        if(arr[mid] == key)
	            return true;
	        else if(arr[mid]>key)
	            e = mid-1;
	        else if(arr[mid]<key)
	            s = mid+1;
	    }
	    return false;
	}
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    sort(arr, arr+n);
	    int c=0;
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
                if(search(arr, n, arr[i]+arr[j])){
                    c++;
                }
	        }
	    }
	    return c;
	}
};

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends