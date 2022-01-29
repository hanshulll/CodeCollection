#include <iostream>
using namespace std;
int isXWinner(int M, int N) {
   if (M % 2 == 0 || N % 2 == 0)
   return 1;
   return 0;
}
int main() {
   int M,N;
  cout<<"enter coin:";
  cin >>M;
  cout<<"enter coin:";
  cin >>N;
   cout<<"Game Starts!\n";
   if(isXWinner(M,N))
      cout<<"Player X is the Winner";
   else
      cout<<"Player Y is the Winner";
   return 0;
}


