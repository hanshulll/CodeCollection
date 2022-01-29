#include <iostream>

using namespace std;


int merge(int *a, int s, int e)
{
    int mid = (s+e)/2;
    
    // 3 pointers for arrays 
    int i = s;             // for 1st array 
    int j = mid + 1;       // for 2nd array 
    int k = s;             // for new array merged
    
    int temp[1000];       // temp array to merge 2 parts in this array 
    
    int count = 0;            // calculate cross inversions here
    
    
    while (i <= mid && j <= e)
    {
        if(a[i] <= a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
            
        }
        
        
        // if a[i] bada toh sab hoga bada vaala bhi pair 
        
        else
        {
            
            temp[k] = a[j];
            k++;
            j++;
            
            // number of elements --> from mid to current i  and + 1 
            // mid - (i-1) --> becoz index starts from 0 
            count = count + (mid - i + 1);
        }
        
    }
    
    
    // fill the elements in new array if remaining in 1st or 2nd array 
    while(i <= mid)
    {
        
        temp[k] = a[i];
        i++;
        k++;
        
    }
    
    while(j <= e)
    {
        
        temp[k] = a[j];
        j++;
        k++;
        
    }
    
    
    // now copy all elements of new array in original array 
    for(int i = s; i <= e; i++)
    {
        a[i] = temp[i];
        
    }
    
    return count;
    
}


int inversion_count(int *arr, int s, int e)
{
    // base case --> if having single element or no element
    
    if(s >= e)
    {
        return 0;
        
    }
    
    // somewhat like merge sort 
    
    int mid = (s+e)/2;
    // Divide Step 
    int x = inversion_count(arr,s,mid);          //  x inversions count in 1st array 
    int y = inversion_count(arr,mid+1,e);        // y inversions count in 2nd array 
    // we will make a merge function 
    int z = merge(arr,s,e);                     // z cross inversion count
    
    
    // return our final answers
    return x+y+z;
    
    
    
}



int main()
{
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;
    int arr[n];
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    
    // function calling, counting the number of inversions
    cout<<inversion_count(arr, 0, n-1) << endl;

    return 0;
}
