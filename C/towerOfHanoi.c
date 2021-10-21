/*
Name - Jayneel Shah
Date - 21/10/21
Topic - Application of Recursion
Program to implement Tower Of Hanoi*/

#include <stdio.h>

void towerOfHanoi(int n, int start, int end)
{
    if (n == 1)
    {
        printf("Move disk from %d to %d.\n", start, end);
    }
    else
    {
        int other = 6 - (start + end);
        //this will move n-1 disks from top of largest disk to the middle disk by the help of recursion
        towerOfHanoi(n - 1, start, other);
        printf("Move disk from %d to %d.\n", start, end);
        //this will move those n-1 disks from middle to the last tower after shifting the largest disk to the last tower
        towerOfHanoi(n - 1, other, end);
    }
}

int main()
{
    int n, towers;
    printf("Enter the number of discs: ");
    scanf("%d", &n);
    printf("Enter the number of towers: ");
    scanf("%d", &towers);
    towerOfHanoi(n, 1, towers);

    return 0;
}
