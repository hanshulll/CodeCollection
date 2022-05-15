#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,i,x,y,pb,j;
	int val[12345],wt[12345];

	while(1)
	{
	scanf("%d%d",&pb,&n);
	if(pb==0&&n==0)break;

	for(i=0;i<n;i++)
	{
		cin>>val[i]>>wt[i];
	}
	int k[n+1][pb+1];

    for(i = 0; i <= n; i++)
    {
        for( j = 0; j <= pb; j++)
        {
            if(i == 0 || j == 0)
                k[i][j] = 0;
            else if(wt[i-1]<=j)
                k[i][j] = max(val[i-1]+k[i-1][j-wt[i-1]], k[i-1][j]);
            else
                k[i][j] = k[i-1][j];
        }
    }
	int maxfun=k[n][pb];
	int minmoney=0;
	for(i=0;i<=pb;i++)
	{
		if(k[n][i]==maxfun)
		{
			minmoney=i;
			break;
		}
	}
	printf("%d %d\n",minmoney,maxfun);
	}
	return 0;
}
