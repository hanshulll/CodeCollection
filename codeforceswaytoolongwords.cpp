#include <iostream>
#include<string.h>
using namespace std;
 
int main() {
	int n,i,j,l[100];
	char s[100][100];
	cin>>n;
	for(i=0;i<n;i++)
	{
	    cin>>s[i];
	    l[i]=strlen(s[i]);
	}
	for(i=0;i<n;i++)
	{
	    if(l[i]>10)
	    {
	        cout<<s[i][0]<<l[i]-2<<s[i][l[i]-1];
	    }
	    else
	    {
	        cout<<s[i];
	    }
	    cout<<endl;
	}
	return 0;
}