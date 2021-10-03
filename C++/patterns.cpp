//right angle triangles
#include<iostream>
using namespace std;
int main()
{
	int i,j,n;
	cin>>n;
		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				cout<<"* ";
			}
				cout<<endl;
		}
		cout<<endl;
		for(i=1;i<=n;i++)
		{
			for(j=n;j>=i;j--)
			{
				cout<<"* ";
			}
				cout<<endl;
		}
		cout<<endl;
		for(i=1;i<=n;i++)
		{
			for(j=n;j>i;j--)
			{
				cout<<"  ";
			}
			for(j=1;j<=i;j++)
			{
				cout<<"* ";
			}
				cout<<endl;
		}
		cout<<endl;
		for(i=0;i<n;i++)
		{
			for(j=1;j<=i;j++)
			{
				cout<<"  ";
			}
			
			for(j=n;j>i;j--)
			{
				cout<<"* ";
			}
				cout<<endl;
		}
return 0;
}
