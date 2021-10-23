/*

CODECHEF PROBLEM:
PROBLRM CODE: ETUP
LINK: https://www.codechef.com/problems/ETUP

*/

#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#define int long long

signed main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
	    int n,q;
	    cin >> n >> q;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin >> arr[i];
	    }
	    int oddps[n];
	    int evenps[n];
	    if (arr[0]%2==0)
	    {
	        evenps[0] = 1;
	        oddps[0] = 0;
	    }
	    else
	    {
	        evenps[0] = 0;
	        oddps[0] = 1;
	    }
	    for(int i=1;i<n;i++)
	    {
	        if (arr[i]%2 == 0)
	        {
	            evenps[i] = 1+evenps[i-1];
	            oddps[i] = oddps[i-1];
	        }
	        else
	        {
	            evenps[i] = evenps[i-1];
	            oddps[i] = oddps[i-1] + 1;
	        }
	    }
	    /*for(int i=0;i<n;i++)
	    {
	        cout << evenps[i] << " ";
	    }
	    cout << endl;
	    for(int i=0;i<n;i++)
	    {
	       cout << oddps[i] << " ";
	    }
	    cout << endl;*/
	    while(q--)
	    {
	        int l,r;
	        cin >> l >> r;
	        int counto = 0;
	        int counte = 0;
	        if(l<=1)
	        {
	            
	        counte = evenps[r-1];
	        counto = oddps[r-1];
	        }
	        else
	        {
	        counte = evenps[r-1] - evenps[l-2];
	        counto = oddps[r-1] - oddps[l-2];
	            
	        }
	        //cout << counto <<" " << counte << endl;
	        int ans = 0;
	        if(counte >= 3)
	        {
	           ans += (counte*(counte-1)*(counte-2))/6;
	        }
	        if(counto >=2 && counte >=1)
	        {
	            ans += ((counto)*(counto-1)*(counte))/2;
	        }
	        cout << ans << endl;
	    }
	}
	return 0;
}
