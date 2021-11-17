#include<stdio.h>
int main()
{
    int n,i,arr[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int max=arr[0],min=arr[0],c=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            c++;
        }
        if(arr[i]<min)
        {
            min=arr[i];
            c++;
        }
    }
    printf("%d\n",c);
}
