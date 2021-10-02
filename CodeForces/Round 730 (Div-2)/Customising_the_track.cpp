// Problem Link: https://codeforces.com/contest/1543/problem/B
//Solution:
 
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
	   // vector<int>v;
	    long long int n;
	    cin>>n;
        vector<long long int>v;
        long long int sum=0;
        for(long long int i=0;i<n;i++)
        {
            long long int inp;
            cin>>inp;
            v.push_back(inp);
            sum+=inp;
        }
    
    // int sum=0;
    long long int avg=sum/n;
    long long int diff=0;
    for(long long int i=0;i<n;i++)
    diff+=(avg-v[i]);
    
    diff=abs(diff);
    long long int res = diff*(n-diff);
    cout<<res<<endl;
	    
	}
// 	return 0;
}