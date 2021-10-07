//josephus problem -> kill every kth person in a circular queue of n people

#include <iostream>
using namespace std;

int jos(int n, int k)
{
    if(n==1)
        return 0;
    return (jos(n-1,k) + k%n)%n;

}

int main()
{

    cout << jos(5,3);
    
 }
   
