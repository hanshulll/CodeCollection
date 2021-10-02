#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {-1,4,6,4,-8,3,5,7,-2,9};
    int n= sizeof(arr)/sizeof(arr[0]);
    int sum =0;
    int midSum =0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<0){
            midSum =0;
        }else{
            midSum +=arr[i];
        }
        sum = max(midSum,sum);
    }
    cout<<sum;
    
}