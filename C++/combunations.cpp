#include <iostream>
using namespace std;
int c(int n, int r){
	if(r == 0 || n == r)
		return 1;
	else 
		return c(n-1,r-1) + c(n-1 , r);
}
int main(){
  int n , r;
	cout<<"n";
  cin>>n;
  cout<<"r";
  cin>>r;
  cout<<"nCr =";
	cout<< c(n ,r);
	return 1;
}
