#include<bits/stdc++.h>
using namespace std;
#define SIZE 20000007
#define inf 1e9
map<int,int> mymap;
vector<int> inv;
vector<int> phi;
void pre()
	{
		int i,j,tem;
		for(i=0;i<SIZE;i++)		{inv.push_back(inf);	phi.push_back(i);}
		inv[1]=1;
		for(i=2;i<SIZE;i++)
			{
				if(phi[i]==i)
					{
						for(j=i;j<SIZE;j+=i)
							{
								tem=(phi[j]/i)*(i-1);
								phi[j]=tem;
							}
					}
			}
		for(i=2;i<SIZE;i++)
			{
				inv[phi[i]]=min(inv[phi[i]],i);
			}
	}
int main()
	{
		pre();
		int t,i,j,n;
		scanf("%d",&t);
		while(t--)
			{
				scanf("%d",&n);
				if(inv[n]==inf)	printf("-1\n");
				else printf("%d\n",inv[n]);
			}
		return 0;
	}
