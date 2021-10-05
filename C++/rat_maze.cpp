#include<iostream>
using namespace std;
bool r_s(int r,int c,int n,int **mz) {
	if( r < 0 || r >= n )
	 return false;
	if( c < 0 || c >= n )
	 return false;
	if(mz[r][c])
	 return true;
	return false;
}
bool s_mz(int ** mz,int i,int j,int **sol,int n) {
	if(i == n-1 && j == n-1) {
		sol[i][j]=1;
		return true;
	}
	if(r_s(i,j,n,mz)) {
		sol[i][j]=1;
		if(s_mz(mz,i+1,j,sol,n))
		 return true;
		if(s_mz(mz,i,j+1,sol,n))
		 return true;
		sol[i][j]=0;
	}
	return false;
}
int main() {
	int n;
	cin>>n;
	int** mz = new int*[n];
	for (int i = 0; i < n; ++i)
	 mz[i] = new int[n];
	int** sol = new int*[n];
	for (int i = 0; i < n; ++i)
	 sol[i] = new int[n];
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			cin>>mz[i][j];
			sol[i][j]=0;
		}
	}
	if(s_mz(mz,0,0,sol,n)) {
		for (int i=0;i<n;i++) {
			for (int j=0;j<n;j++)
			 cout<<sol[i][j]<<" ";
		}
	} else {
		cout<<"-1";
	}
}
