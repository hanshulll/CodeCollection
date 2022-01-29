#include <iostream>

using namespace std;

int mod = (int)1e9 + 7;

int countBT(int h, int *ans){
    if(h == 0 || h == 1){
        return 1;
    }
    if(ans[h] != -1){
        return ans[h];
    }
    ans[h] = (int)((1LL * (countBT(h - 1, ans) % mod) * (( countBT(h - 1, ans) % mod) + ((2 * countBT(h - 2, ans)) % mod))) % mod) ;
    return ans[h];
}

int countBT(int h){
    int *ans = new int[h + 1];
    
    for(int i = 0; i <= h; i++){
        if(i == 0 || i == 1){
            ans[i] = 1;
        }
        else{
            ans[i] = (int)(1LL * (ans[i - 1] % mod)  * ((ans[i - 1] % mod) + ((2 * ans[i - 2]) % mod)) % mod);
        }
    }

    return ans[h];
}

int main(){

    int h;cin>>h;
    int *ans = new int[h + 1];
    for(int i = 0; i <= h; i++){
        ans[i] = -1;
    }
    cout<<countBT(h, ans)<<endl;

    return 0;
}