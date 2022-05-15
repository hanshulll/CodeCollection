/*
code for below pattern
* * * * *  * * * * *
* * * *      * * * *
* * *          * * *
* *              * *
*                  *
*                  *
* *              * *
* * *          * * *
* * * *      * * * *
* * * * *  * * * * *

*/

//Github username: gouravchawla334
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,k=1,j;

   for( i=1;i<=10;i++)
    {
        for(int j=1;j<=11;j++)
        {
            printf(" ");
            if(j<=6-i||j>=6+i ||j<=i-5||j>=17-i)
            printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
