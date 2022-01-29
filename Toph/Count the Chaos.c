#include<stdio.h>
int main()
{
    long long n,i,j,cnet=0;
    scanf("%lld",&n);
    int arr[n];
    for(i=0;i<n;i++)scanf("%lld",&arr[i]);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                cnet++;
            }
        }
    }
    printf("%lld\n",cnet);

    return 0;
}
