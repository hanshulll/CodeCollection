#include <iostream>
#include <cmath>

using namespace std;

int power(int num, int b){
    if(b == 0){
        return 1;
    }
    else if(b % 2 == 0){
        return power(num, b/2) * power(num, b/2);
    }
    else{
        return num * power(num, b/2) * power(num, b/2);
    }
}

int possibilities(int a, int b, int num = 1, int sum = 0){

    int ans = 0;

    int p = power(num, b);

    while(p + sum < a){
        ans += possibilities(a, b, num + 1, sum + p);
        num++;
        p = power(num, b);
    }

    if(p + sum == a){
        ans++;
    }

    return ans;

}

int main(){

    int a,b;cin>>a>>b;
    // int **ans = new int*[a + 1];
    // for(int i = 0; i <= a; i++){
    //     ans[i] = new int[(int)ceil(sqrt(a)) + 1];
    //     for(int j = 0; j <= ceil(sqrt(a)); j++){
    //         ans[i][j] = -1;
    //     }
    // }
    cout<<possibilities(a, b)<<endl;

    return 0;
}