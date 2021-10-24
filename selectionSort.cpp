#include <iostream>
using namespace std;
void selectionsort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
                swap(arr[i],arr[min_idx]);
            }
        }
    }
}
int main()
{
    int arr[]={2,3,7,6,9,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" "; 
    }
}