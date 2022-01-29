#include <bits/stdc++.h>
using namespace std;
bool canThreePartsEqualSum(vector<int>& arr) 
{
    int sum = 0;
    for(int i=0;i<arr.size();i++)
        sum += arr[i];
    if(sum % 3 != 0)
        return false;
    int sum3 = sum/3, partitions = 0;
    sum = 0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(sum == sum3){
            ++partitions;
            sum = 0;
        }
    }
    return partitions >= 3;
}
int main() 
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    vector<int> arr(n); 
    cout << "Enter vector elements: ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    if(canThreePartsEqualSum(arr) == 1)
        cout<< "true" << endl;
    else
        cout << "false" << endl;
}

/*
    Test Case : 1
    
    Enter the size of array: 11
    Enter vector elements: 0 2 1 -6 6 -7 9 1 2 0 1  
    Answer: true

    Test Case : 2

    Enter the size of array: 11
    Enter vector elements: 0 2 1 -6 6 7 9 -1 2 0 1
    Answer: false

    Test Case : 3

    Enter the size of array: 10
    Enter vector elements: 3 3 6 5 -2 2 5 1 -9 4
    Answer: true

    Link: https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
*/