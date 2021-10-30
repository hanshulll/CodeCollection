#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int min,int mid,int max)
{
    int i,j,k,b[100];
    for (i=min;i<=max;i++)
        b[i]=a[i];
    i=min;j=mid+1;k=min;
    while(i<=mid&&j<=max)
    {
        if(b[i]<b[j])
        {
            a[k++]=b[i++];
        }
        else
        {
            a[k++]=b[j++];
        }
    }
    while(i<=mid)
    {
        a[k++]=b[i++];
    }
    while(j<=max)
    {
        a[k++]=b[j++];
    }
}

void msort(int a[],int min,int  max)
{
    int mid;
    if(max>min)
    {
        mid=((min+max)/2);
        msort(a,min,mid);
        msort(a,mid+1,max);
        merge(a,min,mid,max);
    }
}
int main()
{

    int a[100],i,n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter %d elements :",n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    msort(a,0,n-1);
    printf("After sorting : ");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}

/*output  
 Enter the size of array: 8
 Enter 8 elements : 45 89 6 4 28 0 -89 100
 After sorting : -89 4 6 28 45 89 100
 */