#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int left,right,mid,n;
void bubble_sort(int a[]);
int binary_search(int a[],int *key);

void main()
{
    int i,key; 
    int result;
    
    printf("Enter n\n");
    scanf("%d",&n);
    int *a=malloc(n*sizeof(int));
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    bubble_sort(a); //sorting the array
   
    printf("\nThe sorted array is\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    
    printf("\n\nEnter the search element\n");
    scanf("%d",&key);
    
    result=binary_search(a,&key);   //calling the search function
   
    if(result==1)
        printf("Key found in %d position\n",mid+1);
   
    else
        printf("Key not found\n");
   
}
int binary_search(int a[],int *key)
{
    left=0;
    right=n-1;
    do
    {
        mid=(left+right)/2;
        if(*key<a[mid])
            right=mid-1;
        else if(*key>a[mid])
            left=mid+1;
    }
    while(*key !=a[mid] && left<=right);
       
        if(*key==a[mid])
        {
            return 1;
        }
        else return 0;
}

void bubble_sort(int a[])
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}