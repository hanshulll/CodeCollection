#include <iostream>
#include <climits>

using namespace std;

int minStepsTo1(int n, int *ans){
    // Base case
    if(n <= 1){
        ans[n] = 0;
        return 0;
    }
    int a = INT_MAX,b = INT_MAX,c = INT_MAX;

    // Checking whether answer is calculated before
    if(ans[n] != -1){
        return ans[n];
    }

    // Recursive Call
    if(n % 3 == 0){
        a = minStepsTo1(n / 3, ans);
    }
    if(n % 2 == 0){
        b = minStepsTo1(n / 2, ans);
    }
    c = minStepsTo1(n - 1, ans);

    // Storing output for future use
    ans[n] = 1 + min(c, min(a, b));

    // Returning answer
    return ans[n];
}

int minStepsTo1(int n){
    int *ans = new int[n + 1];
    for(int i = 0; i <= n; i++){
        ans[i] = -1;
    }

    for(int i = 1; i <= n; i++){
        if(i == 1){
            ans[i] = 0;
        }
        else{
            int a = INT_MAX, b = INT_MAX, c = INT_MAX;
            if(i % 3 == 0){
                a = ans[i / 3];
            }
            if(i % 2 == 0){
                b = ans[i / 2];
            }
            c = ans[i - 1];
            ans[i] = 1 + min(c, min(a, b));
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
    cout<<minStepsTo1(n, ans);

    return 0;
}