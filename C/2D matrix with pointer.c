#include<stdio.h>
int even(int *, int, int);
int main()
{
	int i,j,evencount;
	int arr[3][5];
	//Input for array
	for(i=0;i<3;i++)
	for(j=0;j<5;j++)
	{	
		printf("Enter element at arr[%d][%d]:-",i,j);
		scanf("%d",&arr[i][j]);
	}
	printf("2D Matrix is:-\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
			{
				printf("%d\t",arr[i][j]);
			}		
		printf("\n");
	}
    evencount=even(&arr[0][0],3,5);
	printf("Even count in array :- %d",evencount);
	return 0;
}
int even(int *p,int r,int c)
{
	int i,j;
	int count=0;//Temporary variable
	for(i=0;i<r;i++)
	for(j=0;j<c;j++)
	{
		if(*((p+i*c)+j)%2==0)//Algo to multiply with no of row with column size to jump to next row
		count++;
	}
	return count;
}
