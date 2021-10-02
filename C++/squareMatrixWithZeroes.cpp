#include <iostream>

using namespace std;

int maxZeroSqMat(int n, int m, int **arr){
    int **ans = new int*[n];
    for(int i = 0; i < n; i++){
        ans[i] = new int[m];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 || j == 0){
                if(arr[i][j] == 0){
                    ans[i][j] = 1;
                }
                else{
                    ans[i][j] = 0;
                }
            }
            else if(arr[i][j] == 1){
                ans[i][j] = 0;
            }
            else{
                ans[i][j] = 1 + min(ans[i - 1][j - 1], min(ans[i - 1][j], ans[i][j - 1]));
            }
        }
    }

    int result = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            result = max(result, ans[i][j]);
        }
    }

    return result;
}

int main(){

    int n,m;
    cin>>n>>m;
    int **arr = new int*[n];
    for(int i = 0; i < n; i++){
        arr[i] = new int[m];
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
        }
    }

    cout<<maxZeroSqMat(n, m, arr)<<endl;

    return 0;
}