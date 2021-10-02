#include <iostream>

using namespace std;

int lootHouses(int *money, int n, int *ans){
    if(n <= 0){
        return 0;
    }

    if(ans[n] != -1){
        return ans[n];
    }

    int a = lootHouses(money + 2, n - 2, ans) + money[0];
    int b = lootHouses(money + 1, n - 1, ans);

    ans[n] = max(a, b);
    return ans[n];
}

int lootHousesDP(int *money, int n){
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = money[0];
    for(int i = 2; i <= n; i++){
        ans[i] = max(money[i - 1] + ans[i - 2], ans[i - 1]);
    }

    return ans[n];
}

int main(){

    int n;cin>>n;
    int *money = new int[n];
    for(int i = 0; i < n; i++){
        cin>>money[i];
    }
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++){
        ans[i] = -1;
    }

    cout<<lootHousesDP(money, n)<<endl;

    return 0;
}