#include <iostream>

using namespace std;

int fibonacci(int n){
    if(n <= 1){
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacci(int *arr, int n){
    if(n <= 1){
        return n;
    }

    // Check if output already exists
    if(arr[n] != -1){
        return arr[n];
    }

    // Calculate output
    int a = fibonacci(arr, n - 1);
    int b = fibonacci(arr, n - 2);

    // Save the output for future use
    arr[n] = a + b;

    // Return the final output
    return arr[n];
}

int fibonacci_2(int n){
    int *arr = new int[n + 1];

    for(int i = 0; i <= n; i++){
        arr[i] = -1;
    }

    return fibonacci(arr, n);
}

int fibonacciIterative(int n){
    int *ans = new int[n + 1];

    for(int i = 0; i <= n; i++){
        if(i <= 1){
            ans[i] = i; 
        }

        ans[i] = ans[i - 1] + ans[i - 2];
    }

    return ans[n];
}

int main(){

    int n;cin>>n;
    cout<<fibonacci_2(n)<<endl;

    return 0;
}