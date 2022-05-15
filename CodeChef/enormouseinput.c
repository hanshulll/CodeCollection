#include<stdio.h>
int main()
{
    int x,y,i,arr[100],cnet=0;
    scanf("%d %d",&x,&y);
    for(i=0; i<x; i++)
    {
        scanf("%d",&arr[i]);
        if(arr[i]%y==0)cnet++;
    }
    printf("%d\n",cnet);
    return 0;
}
