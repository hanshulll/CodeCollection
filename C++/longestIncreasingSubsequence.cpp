#include <iostream>

using namespace std;

int lis(int *arr, int n, int index, int last, int *ans){
    if(index >= n){
        return 0;
    }

    // memoization sirf 2-d me ho skti hai nhi toh inner loop bhi lagana padega recursion me jisse TC O(n^2) ho jaayegi

    int take = 0;
    int dontTake = lis(arr, n, index + 1, last, ans);
    if(arr[index] > last){
        take = 1 + lis(arr, n, index + 1, arr[index], ans);
    }

    return max(take, dontTake);
}

int lisDP(int *arr, int n){
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    for(int i = 2; i <= n; i++){
        ans[i] = 1;
        for(int j = i - 1; j > 0; j--){
            if(arr[j - 1] < arr[i - 1]){
                ans[i] = max(ans[j] + 1, ans[i]);
            }
        }
    }

    int maxi = -1;
    for(int i = 0; i <= n; i++){
        if(maxi < ans[i]){
            maxi = ans[i];
        }
    }
    delete []ans;
    return maxi;
}

int main(){
    int n;cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int *ans = new int[n + 1];
    for(int i = 0; i <= n ;i++){
        ans[i] = -1;
    }

    cout<<lisDP(arr, n)<<endl;
    delete []arr;
    delete []ans;
    return 0;

}