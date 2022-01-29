#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int k = 0; k < n; k++)
    {
        scanf("%d",&a[k]);
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for (int m = 0; m < n; m++)
    {
        printf("%d ",a[m]);
    }
    return 0;
}