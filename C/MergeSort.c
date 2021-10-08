//MERGE SORT

#include<stdio.h>

void merge_sort(int a[100],int low, int high)
{
    int mid;

    if(low < high)
    {
        mid=(low + high)/2;

        merge_sort(a,low,mid);

        merge_sort(a,mid+1,high);

        merge(a,low,mid,high);
    }
}

void merge(int a[100], int low, int mid, int high)
{
    int b[100],j,k,i,l;
    k=low;
    i=low; 
    j=mid+1;

    while((i<=mid) && (j<=high))
    {
        if(a[i] <= a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if(i > mid)
    {
        for(l=j;l<=high;l++)
        {
            b[k]=a[l];
            k++;
        }
    }
    else
    {
        for(l=i;l<=mid;l++)
        {
            b[k]=a[l];
            k++;
        }
    }
    for(k=low;k<=high;k++)
        a[k]=b[k];
}

int main()
{
    int a[100],n,i,high,low;
    low=1;

    printf("Enter size of array : ");
    scanf("%d",&n);
    high=n;

    printf("Enter elements of array : ");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

    merge_sort(a,low,high);

    printf("Sorted array : ");
    for(i=1;i<=n;i++)
        printf("%d\t",a[i]);

    return 0;
}