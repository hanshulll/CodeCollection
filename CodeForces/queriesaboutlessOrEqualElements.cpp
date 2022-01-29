#include <bits/stdc++.h>

using namespace std;


long binary_search(long l, long r, long a[], long x){
	if(r-l <= 1){
		if(a[l]>x)
			return l;
		else if(a[r]>x){
			return r;
		}
		else{
			return r+1;
		}
	}

	long mid = (l+r)/2;
	
	long ans;
	if(x>=a[mid]){
		l = mid+1;
		ans = binary_search(l,r,a,x);
	}
	else{
		r = mid;
		ans = binary_search(l,r,a,x);
	}
	return ans;
}



int main(){
	long n,m;
	cin >> n >> m;
	long a[n], b[m];
	for(long i=0;i<n;i++){
		cin >> a[i];
	}
	for(long i=0;i<m;i++){
		cin >> b[i];
	}

	//sorting a because we have to apply binary search
	sort(a,a+n);
	for(long i=0;i<m;i++){
		long x = binary_search(0,n-1,a,b[i]);
		cout << x << ' ';
	}

}