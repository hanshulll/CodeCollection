//strassens matrix multiplication:
#include <stdio.h>
#include <iomanip>

void display(int n, int arr[50][50])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}
void addmatrices(int n, int a[50][50], int b[50][50], int c[50][50])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
void submatrices(int n, int a[50][50], int b[50][50], int c[50][50])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}
void strassen(int n, int a[50][50], int b[50][50], int c[50][50])
{
    //	printf("inside strassen function for n value %d\n",n);
    if (n == 2)
    {
        //		printf("recursive call starts\n");
        c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
        c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
        c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
        c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
        //		printf("recursive call ends\n");
    }
    else
    {
        int a00[50][50];
        int a01[50][50];
        int a10[50][50];
        int a11[50][50];
        int b00[50][50];
        int b01[50][50];
        int b10[50][50];
        int b11[50][50];
        int c00[50][50];
        int c01[50][50];
        int c10[50][50];
        int c11[50][50];
        //partitioning starts
        //		printf("partitioning starts\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i < n / 2 && j < n / 2)
                {
                    a00[i][j] = a[i][j];
                    b00[i][j] = b[i][j];
                    c00[i][j] = c[i][j];
                }
                if (i < n / 2 && j >= n / 2)
                {
                    a01[i][j - n / 2] = a[i][j];
                    b01[i][j - n / 2] = b[i][j];
                    c01[i][j - n / 2] = c[i][j];
                }
                if (i >= n / 2 && j < n / 2)
                {
                    a10[i - n / 2][j] = a[i][j];
                    b10[i - n / 2][j] = b[i][j];
                    c10[i - n / 2][j] = c[i][j];
                }
                if (i >= n / 2 && j >= n / 2)
                {
                    a11[i - n / 2][j - n / 2] = a[i][j];
                    b11[i - n / 2][j - n / 2] = b[i][j];
                    c11[i - n / 2][j - n / 2] = c[i][j];
                }
            }
        }
        //		printf("partitioning ends \n");
        //partitioning ends
        //		printf("after partitioning array a:\n");display(n/2,a00);display(n/2,a01);display(n/2,a10);display(n/2,a11);

        int p[50][50];
        int q[50][50];
        int r[50][50];
        int s[50][50];
        int t[50][50];
        int u[50][50];
        int v[50][50];
        int p1[50][50];
        int p2[50][50];
        int q1[50][50];
        int r1[50][50];
        int s1[50][50];
        int t1[50][50];
        int u1[50][50];
        int u2[50][50];
        int v1[50][50];
        int v2[50][50];
        addmatrices(n / 2, a00, a11, p1);
        addmatrices(n / 2, b00, b11, p2);
        addmatrices(n / 2, a10, a11, q1);
        submatrices(n / 2, b01, b11, r1);
        submatrices(n / 2, b10, b00, s1);
        addmatrices(n / 2, a00, a01, t1);
        submatrices(n / 2, a10, a00, u1);
        addmatrices(n / 2, b00, b01, u2);
        submatrices(n / 2, a01, a11, v1);
        addmatrices(n / 2, b10, b11, v2);
        //		printf("recursive call starts\n");
        //		printf("strassen p\n");
        strassen(n / 2, p1, p2, p);
        //		printf("strassen q\n");
        strassen(n / 2, q1, b00, q);
        //		printf("strassen r\n");
        strassen(n / 2, a00, r1, r);
        //		printf("strassen s\n");
        strassen(n / 2, a11, s1, s);
        //		printf("strassen t\n");
        strassen(n / 2, t1, b11, t);
        //		printf("strassen u\n");
        strassen(n / 2, u1, u2, u);
        //		printf("strassen v\n");
        strassen(n / 2, v1, v2, v);
        //		printf("recursive call ends\n");
        addmatrices(n / 2, p, s, c00);
        submatrices(n / 2, c00, t, c00);
        addmatrices(n / 2, c00, v, c00);
        addmatrices(n / 2, r, t, c01);
        addmatrices(n / 2, q, s, c10);
        addmatrices(n / 2, p, r, c11);
        submatrices(n / 2, c11, q, c11);
        addmatrices(n / 2, c11, u, c11);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i < n / 2 && j < n / 2)
                {
                    c[i][j] = c00[i][j];
                }
                if (i < n / 2 && j >= n / 2)
                {
                    c[i][j] = c01[i][j - n / 2];
                }
                if (i >= n / 2 && j < n / 2)
                {
                    c[i][j] = c10[i - n / 2][j];
                }
                if (i >= n / 2 && j >= n / 2)
                {
                    c[i][j] = c11[i - n / 2][j - n / 2];
                }
            }
        }
    }
}
int main()
{
    int a[50][50];
    int b[50][50];
    int c[50][50];
    printf("Enter number of elements\n");
    int n;
    //	n=4;

    scanf("%d", &n);
    printf("Enter elements of matrix a\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter elements of row %d\n", i);
        for (int j = 0; j < n; j++)
            //		a[i][j]=j+1;
            scanf("%d", &a[i][j]);
    }
    printf("Enter elements of matrix b\n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter elements of row %d\n", i);
        for (int j = 0; j < n; j++)
            //		b[i][j]=j+1;
            scanf("%d", &b[i][j]);
    }
    //	printf("calling function\n");
    double time_spent = 0.0;
    clock_t begin = clock();
    strassen(n, a, b, c);
    //	printf("function called successfully\n");
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
            printf("%d\t", c[i][j]);
        printf("\n");
    }
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe elapsed time is %f seconds", time_spent);
    return 1;
}
