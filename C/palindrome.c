// This is a program to check whether a number is  palindrome or not

#include <stdio.h>

int ispalindrome(int num)
{
    int reversed = 0;
    int orignaln = num;

    while (num != 0)
    {
        reversed = reversed * 10 + num % 10;
        num = num / 10;
    }
    printf("Reversed number is %d\n", reversed);
    if (orignaln == reversed)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int number;
    printf("Enter a number to check whether it is a palindrome or not \n");
    scanf("%d", &number);

    if (ispalindrome(number))
    {
        printf("The number is palindrome\n");
    }
    else
    {
        printf("The number is not palindrome\n");
    }
    return 0;
}