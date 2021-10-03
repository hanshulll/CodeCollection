//sorting an array using insertion sort.......
#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,j,*p,n,temp=0,k;
    printf("enter the size of the array:\n");
    scanf("%d",&n);
    printf("enter the elements of the array:\n");
    p=(int*)calloc(n,4);
    for(i=0;i<n;i++)
    {
        scanf("%d",(p+i));
    }

printf("sorting the array in ascending order using insertion sort....\n");


        for(i=0;i<n;i++)
        {
            for(j=i;j>0&&*(p+j-1);j--)
            {
                if(*(p+j)<*(p+j-1))
                {
                    temp=*(p+j);
                    *(p+j)=*(p+j-1);
                    *(p+j-1)=temp;
                }
            }
            printf("modified array:");
            for(k=0;k<n;k++)
            {
                printf(" %d",*(p+k));
            }

            printf("\n");


        }


}
