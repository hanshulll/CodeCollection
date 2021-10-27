// C++ program to rotate an array by
// d elements
#include <bits/stdc++.h>
using namespace std;
void leftRotatebyOne(int arr[], int n)
{
    int temp = arr[0], i;
    for (i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
 
    arr[n-1] = temp;
}
void leftRotate(int arr[], int d, int n)
{
    for (int i = 0; i < d; i++)
        leftRotatebyOne(arr, n);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
       cin>>arr[i];}
    
 
    // Function calling
    leftRotate(arr, 2, n);
    print_Array(arr, n);
 
    return 0;
}
