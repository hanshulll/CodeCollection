// Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.
// You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain

#include <iostream>
using namespace std;

#include<climits>
int matrixChainMultiplication(int* p, int n){
    n++;
   
    int m[n][n]; 
    int i, j, k, L, q;
    
    
    // cost is zero when multiplying one matrix.
    for (i=1; i<n; i++)
        m[i][i] = 0;
    
    //L is the chain length
    for (L=2; L<n; L++) {
        for (i=1; i<n-L+1; i++) {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++) {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
    }

    cout << matrixChainMultiplication(arr, n);

    delete[] arr;
}
