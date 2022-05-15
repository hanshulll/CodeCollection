#include <stdio.h>
int main()
{
 int n;
 printf("Enter end number: ");
 scanf("%d", &n);
 printf("Armstrong numbers between 1-%d: ", n);
 int num;
 int c=1;
 int x;
 int p;
 int s;
     while(c<=n)
     {
        num=c;
        s=0;
        while(num)
        {
            x=num%10;
            p=x*x*x;
            s=s+p;
            num=num/10;
        }
            if(c==s)
            {
                printf("%d ", c);
            }
              c++;
     }
     return 0;
}
