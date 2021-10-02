#include <iostream>

using namespace std;

long long coinChange(int *d, int n, int v, int ** ans){
    if(v == 0){
        return 1;
    }
    if(v < 0){
        return 0;
    }
    if(n <= 0){
        return 0;
    }
    if(ans[n][v] != -1){
        return ans[n][v];
    }
    ans[n][v] = coinChange(d, n, v - d[0], ans) + coinChange(d + 1, n - 1, v, ans);

    return ans[n][v];
}

int coinChangeDP(int *d, int n, int v){
    int **ans = new int*[n + 1];
    for(int i = 0; i <= n; i++){
        ans[i] = new int[v + 1];
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= v; j++){
            if(j == 0){
                ans[i][j] = 1;
            }
            else if(i == 0){
                ans[i][j] = 0;
            }
            else if(d[i - 1] > j){
                ans[i][j] = ans[i - 1][j];
            }
            else{
                ans[i][j] = ans[i - 1][j] + ans[i][j - d[i - 1]];
            }
        }
    }

    // for(int i = 0; i<= n; i++){
    //     for(int j = 0; j <= v; j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return ans[n][v];
}

int main(){

    int n;cin>>n;
    int *d = new int[n];
    for(int i = 0; i < n; i++){
        cin>>d[i];
    }
    int v;cin>>v;

    int **ans = new int*[n + 1];
    for(int i = 0; i <= n; i++){
        ans[i] = new int[v + 1];
        for(int j = 0; j <= v; j++){
            ans[i][j] = -1;
        }
    }

    cout<<coinChangeDP(d, n, v)<<endl;

    return 0;
}