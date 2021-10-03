#include<stdio.h>
#include<stdlib.h>

int lsearch(int n,int *arr,int search)
{
    int res=0;
    int i;
    for( i=0;i<n;i++)
    {
        if(search==arr[i])
        {
            res=1;
            break;
        }
    }
    if(res==0)
        return -1;
    
    else return i;
}

int main()
{
    int n,*arr,search,res=0;
    
    printf("Enter n\n");
    scanf("%d",&n);
    
    arr=(int*)malloc(n*sizeof(int));
    
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    printf("Enter the search element: ");
    scanf("%d",&search);
    
    res=lsearch(n,arr,search);
    
    if(res==-1)
    printf("Element not found\n");
    
    else printf("Element found at %d position\n",res+1);
}