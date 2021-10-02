#include <iostream>

using namespace std;

int staircase(int n, int *ans){
    if(n == 0 || n == 1){
        return 1;
    }
    else if(n == 2){
        return 2;
    }

    if(ans[n] != -1){
        return ans[n];
    }
    int a = staircase(n - 1, ans);
    int b = staircase(n - 2, ans);
    int c = staircase(n - 3, ans);

    ans[n] = a + b + c;
    return ans[n];
}

int staircase(int n){
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++){
        if(i <= 1){
            ans[i] = 1;
        }
        else if(i == 2){
            ans[i] = 2;
        }
        else{
            ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
        }
    }

    return ans[n];
}

int main(){

    int n;cin>>n;
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++){
        ans[i] = -1;
    }
    cout<<staircase(n)<<endl;

    return 0;
}