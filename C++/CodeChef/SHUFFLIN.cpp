#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int main() {
	int T;
	cin>>T;
	if(T>=1)
	{
	    for(int j=0;j<T;j++)
	    {
	        int N,ec=0,oc=0,even,odd;
	        cin>>N;
	        int A[N];
	        if(N>=1)
	        {	        
    	        if(N%2==0)
    	        {
    	            even=N/2;
    	            odd=N/2;
    	        }
    	        else
    	        {
    	            even=(N-1)/2;
    	            odd=(N+1)/2;
    	        }
    	            for(int i=1;i<=N;i++)
    	            {
        	            cin>>A[i];
        	            if(A[i]%2==0)
        	            ec++;
        	            else
        	            oc++;
	            }
	        cout<< min(odd,ec)+min(even,oc)<<endl;
	        }
	    }
	}
	return 0;
}
