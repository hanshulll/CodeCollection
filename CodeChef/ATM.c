#include<stdio.h>
int main()
{
    int x;
    double y,wid;
    printf("Input:\n");
    scanf("%d %lf",&x,&y);
    if(x%5==0)
    {
        wid=((y-x)-0.50);
        printf("Output:\n");
        printf("%0.2lf\n",wid);
    }
    else if(x>y)
    {
        printf("Output:\n");
        printf("%0.2lf\n",y);

    }

    return 0;
}
