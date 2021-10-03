#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

int majorityElement(int arr[], int size)
{
     if(size == 1) return arr[0];
    if(size == 2) return -1;
    
    int count = 1, res = arr[0];
    
    for(int i = 1; i < size; i++)
    {
        if(arr[i] == res) count++;
        else count--;
        
        if(count == 0)
        {
            res = arr[i];
            count = 1;
        }
    }
    
    count = 0;
    for(int i = 0; i < size; i++)
    if(arr[i] == res) count++;
    
    if(count > size/2) return res;
    return -1;
    
}


// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends
