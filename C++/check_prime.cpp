#include<bits/stdc++.h>
using namespace std;

// function to check a numebr is prime or not
bool isPrime(int n){
    if (n <= 1)                  // 1 is not a prime number
        return false;
    if (n <= 3)                  // 2 and 3 are prime numbers
        return true;
    if (n % 2 == 0 || n % 3 == 0)           // Multiple of 2 and 3 will not be prime
        return false;
         
    for (int i = 5; i * i <= n; i = i + 6)      // Now we have to only check that 
        if (n % i == 0 || n % (i + 2) == 0)         // number should not be multiple of 6 (-,+) 1
            return false;
    return true;
}

int main(){
    
    int n;
    cout<<"Enter a number: ";
    cin >> n;
    
    if(isPrime(n))
        cout << n << " is a prime number\n";
    else
        cout << n << " is not a prime number\n";
    

    return 0;
}   
