// { Driver Code Starts
#include <stdio.h>

void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}
// } Driver Code Ends


void rotate(int arr[], int n)
{
    int *a = (int*)malloc(n*sizeof(int));
    a[0] = arr[n-1];
    for(int i=0, j=1 ;i<n-1, j<n ; i++, j++){
        a[j] = arr[i];
    }
    // arr = a
    int i=0;
    while(i<n){
        arr[i] = a[i];
        i++;
    }
}