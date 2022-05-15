#include<iostream>
using namespace std;

int main() {
    int n,binary=0,i=1,rem;
	cin>>n;
	while(n!=0)
	{
		rem=n%2;
		binary=binary+(rem*i);
        n=n/2;
		i*=10;
	}
	cout<<binary;
}