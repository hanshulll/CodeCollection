#include<stdio.h>
int main()
{
int mat[6][6],sym_mat[6][6];
printf("enter the elements of the matrix\n");
for(int i=0;i<6;i++)
{
    for(int j=0;j<6;j++)
    {
        scanf("%d",&mat[i][j]);
    }
}
printf("the original matrix is as follows:\n");
for(int i=0;i<6;i++)
{
    for(int j=0;j<6;j++)
    {
        printf("%d ",mat[i][j]);
    }
    printf("\n");
}
printf("------------xxx----------");
printf("\n");
printf("the symmetric matrix is as follows:\n");
for(int i=0;i<6;i++)
{
    for(int j=0;j<6;j++)
    {
        printf("%d ",mat[j][i]);
    }
    printf("\n");
}
return 0;
}