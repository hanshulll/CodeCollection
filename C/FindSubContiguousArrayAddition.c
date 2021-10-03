#include <stdio.h>
int main()
{
    int n, S;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array.\n");
    for (int m = 0; m < n; m++)
    {
        scanf("%d", &arr[m]);
    }
    printf("Enter the no of which you want the sum of elements to be equal to:- \n");
    scanf("%d", &S);
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == S)
            {
                for (int p = i; p <= j; p++)
                {
                    printf("%d ", arr[p]);
                }
                printf("\n");
                break;
            }
        }
    }
    return 0;
}