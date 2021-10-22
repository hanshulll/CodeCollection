#include <bits/stdc++.h>
using namespace std;

void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low-1;
    int j = high+1;
    
    while(true) {
        do {
            i++;
        } while(arr[i] < pivot);
        
        do {
            j--;
        } while(arr[j] > pivot);
        
        if(i >= j)
            return j;
        
        swap(&arr[i], &arr[j]);
    }
    
}


int partitionRandom(int arr[], int low, int high) {
    
    srand(time(NULL));
    
    int random = low + rand()%(high - low);
    
    swap(&arr[random], &arr[low]);
    
    return partition(arr, low, high);
    
}

void quicksort(int arr[], int low, int high) {
    
    if(low < high) {
        int pi = partitionRandom(arr, low, high);
        quicksort(arr, low, pi);
        quicksort(arr,pi+1, high);
    }
    
}

int main()
{
    int n = 0;    
    cout<<"Enter the size of the array: ";
    cin>>n;
    
    int arr[n];   
    cout<<"\nEnter the array elements"<<endl;
    
    for(int i = 0; i < n; i++) 
        cin>>arr[i];
    
    cout<<"\nSorted array: ";
    quicksort(arr, 0, n-1);
    for(auto i : arr) 
        cout<<i<<" ";

    return 0;
}