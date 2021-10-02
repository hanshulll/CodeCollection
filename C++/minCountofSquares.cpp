#include <iostream>
#include <cmath>

using namespace std;

int minCount(int n, int *ans){
    if(sqrt(n) - floor(sqrt(n)) == 0){
        return 1;
    }
    if(n <= 3){
        return n;
    }

    if(ans[n] != -1){
        return ans[n];
    }

    int result = n;
    for(int i = 1; i <= n; i++){
        int temp = i * i;
        if(temp > n){
            break;
        }
        else{
            result = min(result,1 + minCount(n - temp, ans));
        }
    }
    ans[n] = result;
    return ans[n];
}

int minCount(int n){
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++){
        if(i <= 3){
            ans[i] = i;
        }
        else if(sqrt(i) - floor(sqrt(i)) == 0){
            ans[i] = 1;
        }
        else{
            ans[i] = i;

            for(int x = 1; x <= i; x++){
                int temp = x * x;
                if(temp > i){
                    break;
                }
                else{
                    ans[i] = min(ans[i], 1 + ans[i - temp]);
                }
            }
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
    cout<<minCount(n)<<endl;

    return 0;
}