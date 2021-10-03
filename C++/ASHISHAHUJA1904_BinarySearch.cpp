#include <iostream>
using namespace std;
//binary search implementation (assuming that the given array is arranged in ascending order)
int binarysearch(int array[],int begin,int end,int element){
    while(begin<=end){
        int mid = begin + (end-begin)/2;
        if(array[mid]==element){
            cout<<"Found!!!";
            return 0;
        }
        else if(array[mid]<element){
            begin = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    cout<<"Not Found!!!";
    return 0;
} 
int main()
{
    int element,array[]={1,23,28,34,37,56,78,83,89,90};
    cout<<"Enter the element you want to search:";
    cin>>element;
    int size=sizeof(array)/sizeof(array[0]);
    binarysearch(array,0,size-1,element);
    return 0;
}