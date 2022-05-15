//Fibonacci Series using Recursion
#include<stdio.h>
int fib(int n) //Function to return nth fibonacci number
{
   if (n <= 1)
      return n;
   return fib(n-1) + fib(n-2);
}
 
int main ()
{
  int n = 10;
  printf("%d", fib(n));
  getchar();
  return 0;
}
