#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int i,a=0,b=0,c=0;
		int n=s.length();
		
		for(i=0;i<n;i++)
		{
			if(s[i]=='A')
				a++;
			else if(s[i]=='B')
				b++;
			else if(s[i]=='C')
				c++;

		}

		if(a+c==b)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		
	}
	return 0;
}