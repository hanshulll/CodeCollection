#include<stdio.h>
#include<stdlib.h>

void swap(int a[], int b, int c)
{
	int temp;
	temp=a[b];
	a[b]=a[c];
	a[c]=temp;
}

void quicksort(int a[], int left, int right)
{
	int i,j,pivot;
	if(left<right)
	{
		pivot=a[left];
		i=left+1; 
		j=right;
		while(1)
		{
			while(i<right && pivot>=a[i])
                i++;
			while(pivot<a[j])
                j--;
			if(i<j)
				swap(a,i,j);
			else
            { 
				swap(a,left,j);
				break;
			}
		}
		quicksort(a,left,j-1);
		quicksort(a,j+1,right);
	}
}

void main()
{
	int i,n;
    printf("Enter the size of array\n");
	scanf("%d",&n);
	int* a =(int*)malloc(n*sizeof(int));
    if(a== NULL)
    {
        printf("Null pointer\n");
        exit(1);
    }
	printf("Enter the array elements(%d)\n",n);
    
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
    
	quicksort(a,0,n-1);
	printf("The sorted array is :\n");
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
    
	printf("\n");
}