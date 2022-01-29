//Author: Sanjana Sawant

#include<stdio.h>
#define MAX 20

int main()
{
    int a[MAX], i=0, j=0, n ;
    int temp, flag =0;

    printf("-----------Program for BUBBLE Sort Algorithm------------- \n");

    //Input
    printf("\nEnter the number of elements in the list : ");
    scanf("%d",&n);

    printf("\nEnter %d numbers : \n", n);
    for (int i =0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    //Bubble sort Algorithm
    for (i=0; i<n-1; i++)
    {
        for (j=0; j<n-1-i; j++)
        {
            //Swap the larger element
            if (a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag =1;
            }
        }
        if (flag ==0)
        {
            break;
        }
    }

    //If the input array was already sorted, the number of passes is 1
    printf("\n\nNumber of passes : %d ",i+1);

    printf("\n\nSorted array : \n");
    for (i=0; i< n; i++)
    {
        printf("%d \n", a[i]);
    }

    printf("\n\n");
}
