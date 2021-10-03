// Find the factorial of the number


// input : 4
//output : 24

#include<bits/stdc++.h>
using namespace std;
  
int fib(int n)
{
    if(n<=1)
    {
        return 1;
    }
    
    return n* fib(n-1);
}
int main()
{
    int n=5;
    auto p = fact(n);
    cout<<p;
}