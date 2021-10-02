#include <iostream>
#include <climits>

using namespace std;

int mcm(int *arr, int start, int end, int **ans){
    if(start >= end){
        return 0;
    }

    if(ans[start][end] != -1){
        return ans[start][end];
    }

    int count = 0;
    ans[start][end] = INT_MAX;

    for(int j = start; j < end; j++){
        count = mcm(arr, start, j, ans) + mcm(arr, j + 1, end, ans) + arr[start - 1] * arr[j] * arr[end];

        ans[start][end] = min(ans[start][end], count);
    }

    return ans[start][end];
}

int main(){

    int n;
    cin>>n;
    int arr[n + 1];
    for(int i = 0; i <= n; i++){
        cin>>arr[i];
    }

    int **ans = new int*[n + 1];
    for(int i = 0; i <= n ; i++){
        ans[i] = new int[n + 1];
        for(int j = 0; j <= n; j++){
            ans[i][j] = -1;
        }
    }

    cout<<mcm(arr, 1, n, ans)<<endl;

    return 0;
}