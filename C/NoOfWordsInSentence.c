/*
 * Write a program in C to find the number of words present in a given sentence
 */
#include <stdio.h>
#include <string.h>
 
void main()
{
    char sentence[200];
    int count = 0, i;
 
    printf("Enter the sentence:\n");
    scanf("%[^\n]sentence", sentence);
    for (i = 0;sentence[i] != '\0';i++)
    {
        if (sentence[i] == ' ' && sentence[i+1] != ' ')
            count++;    
    }
    printf("Number of words in given sentence are: %d\n", count + 1);
}