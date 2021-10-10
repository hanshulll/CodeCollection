/*

October Challenge 2021 Division 3  » MEX-OR

Problem Code : MEXOR

Link : https://www.codechef.com/OCT21C/problems/MEXOR

*/

#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
int main() {
	int T;
	cin>>T;
	while(T--)
	{
	        int x,output;cin>>x;
	        
	        if(x==0){
	            cout<<"1\n";
	        }
	        else if(x==1){
	            cout<<"2\n";
	        }
	        else if(x==2){
	            cout<<"2\n";
	        }
	        else{
	            output=1;
	        while(2*output<=x){
	            output*=2;
	        }
	        if(output==x){
	            cout<<x<<endl;
	        }
	        else if(x==(2*output-1)){
	            cout<<x+1<<endl;
	        }
	        else{
	            cout<<output<<endl;
	        }
	    }
	}
	return 0;
}