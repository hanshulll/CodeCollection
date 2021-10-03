#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main()
{
    int num,sqr;
    time_t now;
    time(&now);
    char buffer[MAX_COMPUTERNAME_LENGTH + 1];

    printf("Enter The Number: ");
    scanf("%d",&num);

    sqr = num*num;

    printf("\nSquare Value of %d = %d ",num,sqr);
    printf("--printed time: %s",ctime(&now));

    DWORD size = MAX_COMPUTERNAME_LENGTH + 1;
    GetComputerName(buffer,&size);

    printf("\nComputer Name = %s\n",buffer);

    system("getmac");
    getchar();

    return 0;
}
