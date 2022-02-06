#include<stdio.h>
int main()
{
	int i,j,n,s;
	int arr[11]={2,5,7,8,14,16,22,25,30,45};
	printf("The sorted array is:-\n");
	for(i=0;i<10;i++)
	printf("%d, ",arr[i]);
	//New element to insert
	printf("\nEnter the new element to be inserted:-");
	scanf("%d",&n);
	//Put element in array using shift
	for(i=0;i<10;i++)
	{
		if(arr[i]<n)
		continue;
		else
		{
			s=i;
			break;
		}
	}
	s=i;	
    for(i=9;i>=s;i--)
	arr[i+1]=arr[i];	//Shifting
	arr[s]=n;
	printf("The new sorted array after insertion is:-\n");
	for(i=0;i<11;i++)
	printf("%d, ",arr[i]);
	return 0;
}
