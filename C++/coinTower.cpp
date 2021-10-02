#include <iostream>

using namespace std;

bool coinTower(int n, int x, int y, int *ans){
    if(n == 0){
        return 0;
    }
    if(n < 0){
        return 1;
    }
    if(ans[n] != -1){
        return ans[n];
    }

    ans[n] = coinTower(n - 1, x, y, ans)^1 || coinTower(n - x, x, y, ans)^1 || coinTower(n - y, x, y, ans)^1;

    return ans[n];
}

bool coinTowerDP(int n, int x, int y){
    int ans[n + 1];
    ans[0] = 0;
    ans[1] = 1;

    for(int i = 2; i <= n; i++){
        if(i >= 1 && !ans[i - 1]){
            ans[i] = 1;
        }
        else if(i >= x && !ans[i - x]){
            ans[i] = 1;
        }
        else if(i >= y && !ans[i - y]){
            ans[i] = 1;
        }
        else{
            ans[i] = 0;
        }
    }

    return ans[n];
}

int main(){

    int n, x, y;
    cin>>n>>x>>y;

    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++){
        ans[i] = -1;
    }

    if(coinTowerDP(n, x, y)){
        cout<<"Beerus\n";
    }
    else{
        cout<<"Whis\n";
    }

    return 0;
}