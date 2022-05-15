#include<iostream>
using namespace std;


// Normal Binary Search:
void binarySearch(int arr[], int n, int x){
    first = 0;
    last = n-1;
    middle = (first+last)/2;
    while(first <= last)
    {
        if(arr[middle]<num)
            first = middle+1;
        else if(arr[middle]==num)
        {
            cout<<"\nThe number, "<<num<<" found at Position "<<middle+1;
            break;
        }
        else
            last = middle-1;
        middle = (first+last)/2;
    }
    if(first>last)
        cout<<"\nThe number, "<<num<<" is not found in given Array";
    cout<<endl;
}

// Recursive Binary Search:

int BinarySearchRecur(int arr[], int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    int i, n, num, first, last, middle;
    cout<<"Enter the number of Elements to be taken:- ";
    cin>>n;
    int arr[n];
    cout<<"Enter n Elements (in ascending order): ";
    for(i=0; i<n; i++)
        cin>>arr[i];
    cout<<"\nEnter Element to be Search: ";
    cin>>num;
    binarySearch(arr, n, num);
    BinarySearchRecur(arr, 0, n-1, num);
    return 0;
}
