#include <stdio.h>
#include <stdlib.h>
/*
User:  enter a number
system: print all the factors of that number
*/

void printFactors(int number);

int main()
{
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    printFactors(number);
    return 0;
}

void printFactors(int number){

    int count = 0;
    for(int i=1; i<=number; i++){
        if(number%i == 0){
            printf("%d \t",i);
            count++;
        }
    }
    printf("\n");

    if(count == 2){
        printf("Primitive \n");
    }

}
