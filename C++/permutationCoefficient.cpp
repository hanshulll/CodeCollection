#include <iostream>

using namespace std;

const int mod = (int)1e9 + 7;

int perm(int n, int r){
    int ans[n + 1][r + 1];
    for(int i = 0 ; i <= n ; i++){
        for(int j = 0 ; j <= r; j++){
            if(j > i){
                ans[i][j] = 0;
            }
            else if(j == 0){
                ans[i][j] = 1;
            }
            else{
                ans[i][j] = (ans[i - 1][j] + (j * ans[i - 1][j - 1]) % mod) % mod;
            }
        }
    }

    return ans[n][r];
}

int main(){

    int n, r;
    cin>>n>>r;
    cout<<perm(n, r)<<"\n";

    return 0;
}