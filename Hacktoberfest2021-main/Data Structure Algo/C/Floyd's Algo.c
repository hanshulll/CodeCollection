#include<stdio.h>
#include<time.h>
double clk;
clock_t starttime,endtime;
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}
void floyd(int n,int W[10][10],int a[10][10])
{
   	int i,j,k;
	for(i=0;i<n;i++)
    {
	    for(j=0;j<n;j++)
        {
	    a[i][j]=W[i][j];      //D is the answer matrix
        }
    }

	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);  //if added result is smaller that is chosen.
			}
		}
	}
}
void main()
{
	int i,j,n,a[10][10],W[10][10];
	printf("Enter no.of vertices: \n");
	scanf("%d",&n);
	printf("Enter the cost matrix: \n");
	for(i=0;i<n;i++)
    {
	    for(j=0;j<n;j++)
        {
	    scanf("%d",&W[i][j]);
        }
    }
	starttime=clock();
    floyd(n,W,a);
    endtime=clock();
    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
    printf("All pair shortest path matrix is\n");
	for(i=0;i<n;i++)
	{   printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
	}

   printf("\nThe run time is %f\n",clk);
}
