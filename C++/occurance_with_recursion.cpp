//RECURSION
// Find the first and last occurrence of an element using recursion
// Objective: To find the first occurrence, we return as soon as we find the element.
// To find the last occurrence, we return the result we get from further function
// calls.
// Base Case would be when you reach the end of the array.
// Time Complexity: O(N)
// Space Complexity: O(N) for function call stack

#include<bits/stdc++.h>
using namespace std;

int firstOccurance (int arr[], int n, int key, int i){
    if(i<n){
        if (arr[i]==key){
            return i;
        }
        else
        return firstOccurance (arr,n, key,++i);
    }
    else{
        return -1;
    }
}

int lastOccurance (int arr[],int n,int key, int i,int pos){
    if(i==(n-1)){
        if(arr[i]==key){
        pos=i;
        }
    }
    else{
        if(arr[i]==key){
            pos=i;    
        }
        pos=lastOccurance(arr,n,key,++i,pos);
    }
    return pos;
}

int main(){
    int n,key;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>key;
    cout<<firstOccurance (arr,n,key,0);
    cout<<endl;
    cout<<lastOccurance (arr,n,key,0,-1);
}