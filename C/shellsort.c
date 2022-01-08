#include<stdio.h>

void shellSort(int arr[],int n)
{
    int i,j,m,temp;
    for(m = n/2; m > 0; m /=2)
    {
        for(j=m;j<n;j++)
        {
            for(i = j-m;i>=0;i-=m){
                if(arr[i+m] > arr[i])
                break;
                else{
                    temp = arr[i];
                    arr[i] = arr[i+m];
                    arr[i+m] = temp;
                }
            }
        }
    }
}

int main()
{
    int arr[100], n, i, j;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter  the elements: ");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Array before sorting:");
    for (i = 0; i < n; i++){
        printf(" %d ", arr[i]);
    }
    shellSort(arr,n);
    printf("\nSorted Array using shell Sort:");
    for(i = 0; i < n; i++){ 
        printf(" %d ", arr[i]);
    }
return 0;
}

