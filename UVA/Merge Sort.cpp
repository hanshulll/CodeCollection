#include<stdio.h>
int arr[1000],arr2[1000];
void mergesort(int start,int mid,int end)
{
    int i,cnet=0;
    for(i=start; i<=end; i++)
        arr2[i]=arr[i];
    int x=start,lhs=start,rhs=mid+1;
    while(lhs<=mid && rhs<=end)
    {
        if(arr2[lhs]<arr2[rhs])
        {
            arr[x++]=arr2[lhs++];
            cnet++;
        }

        else
        {
            arr[x++]=arr2[rhs++];
            cnet++;
        }

    }
    while(lhs<=mid)
    {
        arr[x++]=arr2[lhs++];
    }
    while(rhs<=end)
    {
        arr[x++]=arr2[rhs++];
    }
}
void merge(int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        merge(start,mid);
        merge(mid+1,end);
        mergesort(start,mid,end);
    }
}
int main()
{
    int n,i,cnet=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int start=0,end=n-1;
    merge(start,end);
    printf("%d\n",cnet);
    for(i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
