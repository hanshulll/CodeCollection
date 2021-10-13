//program to implement tower of hanoi for any number of disks

#include<stdio.h>
//recursive function to implement tower of hanoi
void tower_of_hanoi(int n, int from, int to, int aux)
{   
    //base condition
    if(n==1)
    {
        printf("\nmove disk 1 from rod %d to rod %d\n",from,to);
        return;
    }
    //recursive condition
    tower_of_hanoi(n-1,from,aux,to);
    printf("\nmove disk %d from rod %d to rod %d",n,from,to);
    tower_of_hanoi(n-1,aux,to,from);
}
//driver code
int main(void)
{
    int num;
    printf("\n\t\t\tTOWER OF HANOI\n");
    //accepting number of disks
    printf("\nenter the number of disks:\t");
    scanf("%d",&num);
    //function call
    tower_of_hanoi(num,1,3,2);
}
