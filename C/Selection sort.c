#include <stdio.h>
void selectionSort(int a[],int n){
    int i,j,min,swap;
    for(i = 0; i < n - 1; i++)
    {
        min=i;
    for(j = i + 1; j < n; j++)
    {
    if(a[j] < a[min])
        min=j;
    }
    if(min != i)
    {
        swap=a[i];
        a[i]=a[min];
        a[min]=swap;
        }
    }
}

int main()
{
    int a[100], n, i, j;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter  the elements: ");
    for (i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("Array before sorting:");
    for (i = 0; i < n; i++){
        printf(" %d ", a[i]);
    }
    selectionSort(a,n);
    printf("\nSorted Array using selection Sort:");
    for(i = 0; i < n; i++){ 
        printf(" %d ", a[i]);
    }
return 0;
}