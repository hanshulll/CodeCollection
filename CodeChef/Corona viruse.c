#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t,n,x[100],i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%d",&x[i]);
        }
        int min=1,high=0;
        for(i=0; i<n; i++)
        {
            int cnet=0;
            if(i+1==n)break;
            if(x[i]<x[i+1])
            {
                cnet=abs(x[i]-x[i+1]);
            }
            if(cnet<=2)
            {
                high++;
                min++;
            }
            else if(cnet<=1)high++;
            else if(cnet<=3)min=high;
        }

        printf("%d %d\n",min,high);
    }
    return 0;

}
