//Author Tejas K Mukherjee
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define FOR(a,b) for(int i=a;i<b;i++)
#define FORE(a,b) for(int i=a;i<=b;i++)
bool perfSquare(long double x) 
{   
  // Find floating point value of  
  // square root of x. 
  long double sr = sqrt(x); 
  
  // If square root is an integer 
  return ((sr - floor(sr)) == 0); 
} 
bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1) 
        return false; 
  
    // Check from 2 to n-1 
    for (int i = 2; i <= sqrt(n); i++) 
        if (n % i == 0) 
            return false; 
  
    return true; 
} 
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        ll tprime;
        cin>>tprime;
        if (!perfSquare(tprime))
            cout<<"NO"<<'\n';
        else
        {
            if (isPrime(sqrt(tprime)))
                cout<<"YES"<<'\n';
            else    
                cout<<"NO"<<'\n';
        }
    }
    return 0;
}