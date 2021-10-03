#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int rows, cols;
int arr[101][101];
int ans[101][101];

int minCostPath(int m, int n){
    if(m == 0 && n == 0){
        return arr[m][n];
    }
    if(ans[m][n] != -1){
        return ans[m][n];
    }
    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    if(m > 0){
        x = minCostPath(m - 1, n) + arr[m][n]; 
    }
    if(n > 0){
        y = minCostPath(m, n - 1) + arr[m][n];
    }
    if(m > 0 && n > 0){
        z = minCostPath(m - 1, n - 1) + arr[m][n];
    }

    ans[m][n] = min(z, min(x, y));
    return ans[m][n];

}

int minCostPathDP(int m, int n){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0){
                ans[i][j] = arr[i][j];
            }
            else if(i == 0){
                ans[i][j] = arr[i][j] + ans[i][j - 1];
            }
            else if(j == 0){
                ans[i][j] = arr[i][j] + ans[i - 1][j];
            }
            else{
                ans[i][j] = arr[i][j] + min(ans[i - 1][j - 1], min(ans[i - 1][j], ans[i][j - 1]));
            }
        }
    }

    // Debug karra tha
    // for(int i = 0; i < m; i++){
    //     for(int j = 0; j < n; j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return ans[m - 1][n - 1];
}

int main(){

    memset(ans, -1, sizeof(ans));

    cin>>rows>>cols;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cin>>arr[i][j];
        }
    }

    cout<< minCostPathDP(rows, cols);

    return 0;
}