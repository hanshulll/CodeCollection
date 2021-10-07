//c++ program to convert decimal to binary

#include <bits/stdc++.h>
using namespace std;
int decToBin(int n)
{
   int pow = 1;
   int res = 0;
   while(n)
   {
      
      if(n&1)
      res = res + pow;

     pow  = pow*10;
      n = n>>1;
      
   }

   return res;

}

int32_t main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 
 int n;
 cin>>n;
 cout<<decToBin(n);
 
}