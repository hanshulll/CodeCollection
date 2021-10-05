#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rps(char you, char comp);
int main(int argc, char const *argv[])
{
    char you, comp;

    int num;
    srand(time(0));
    num = rand() % 100 + 1;
    if (num < 33)
    {
        comp = 'r';
    }
    else if (num > 33 && num < 66)
    {
        comp = 'p';
    }
    else if (num > 66)
    {
        comp = 's';
    }

    printf("For rock - press 'r', for paper - press 'p', for scissor - press 's' : ");
    scanf("%c", &you);
    printf("You have chosen %c and computer has chosen %c\n", you, comp);

    int result = rps(you, comp);
    if (result == 0)
    {
        printf("Game draw\n");
    }
    if (result == 1)
    {
        printf("You won!\n");
    }
    if (result == -1)
    {
        printf("You lose\n");
    }
    if (result == 2)
    {
        printf("INVALID INPUT\n");
    }

    return 0;
}
int rps(char you, char comp)
{
    if (you == comp)
    {
        return 0;
    }

    if (you == 'r' && comp == 'p')
    {
        return -1;
    }
    else if (you == 'p' && comp == 'r')
    {
        return 1;
    }

    if (you == 's' && comp == 'r')
    {
        return -1;
    }
    else if (you == 'r' && comp == 's')
    {
        return 1;
    }

    if (you == 'p' && comp == 's')
    {
        return -1;
    }
    else if (you == 's' && comp == 'p')
    {
        return 1;
    }
}