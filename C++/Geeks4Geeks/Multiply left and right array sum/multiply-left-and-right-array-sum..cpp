// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

int multiply(int arr[], int n);


int main() {
	//code
	int t;
	cin>>t;
	while (t--)
	{
	    int n,sum1=0,sum2=0;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    
	    cout << multiply(a, n) << endl;
	    
	}
	return 0;
}// } Driver Code Ends


//User function Template for C++

int leftadd(int arr[], int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int rightadd(int arr[], int start, int end){
    int sum = 0;
    for(int i=start; i<end; i++){
        sum += arr[i];
    }
    return sum;
}

int multiply(int arr[], int n)
{
    // Complete the function
    int len = n/2;
    int leftSum = leftadd(arr, len);
    int rightSum = rightadd(arr, len, n);
    return leftSum*rightSum;
}