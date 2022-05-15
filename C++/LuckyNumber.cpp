// Codeforces Problem
// Link - https://codeforces.com/problemset/problem/122/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
  // Input taking N.
  int N;
  cin>>N;
  
  bool flag=0;

  // All numbers of 1, 21 3digits of 4 and 7.
  int arr[12]={4,7,47,74,44,444,447,474,477,777,774,744};
  
  // Checking if given number is satisfying condition or not.
  for(int i=0;i<12;i++)
  {
    if(N%arr[i]==0)
    {
      flag=true;
    }
  }

  // Printing Output
  if(flag)
    cout<<"YES";
  else
    cout<<"NO";

  return 0;
}
