#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Key missing\n");
        return 1;
    }

    int upper = 65;
    int lower = 97;

    //if all alphabets are present in key, upper will be equal to 91
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            int k = argv[1][j];
            if (k == upper || k == lower)
            {
                upper++;
                lower++;
            }
        }
    }

    //handles cases where the key is incorrect
    int n = strlen(argv[1]);
    if (argc != 2 || n != 26 || upper != 91)
    {
        printf("Incorrect Key Format\n");
        return 1;
    }

    //Handles cases where the key is correct
    else
    {
        //input plaintext from user
        string input = get_string("plaintext:");
        int l = strlen(input);

        printf("ciphertext:");

        //cipher backend calculations looping through each character
        for (int m = 0; m < l; m++)
        {
            int key_index;

            if (input[m] >= 'A' && input[m] <= 'Z')   //input is uppercase
            {
                key_index = input[m] - 65;

                if (argv[1][key_index] >= 'A' && argv[1][key_index] <= 'Z')
                {
                    printf("%c", argv[1][key_index]);
                    continue;
                }
                else
                {
                    printf("%c", argv[1][key_index] - 32);
                    continue;
                }
            }

            else if (input[m] >= 'a' && input[m] <= 'z')  //input is lowercase
            {
                key_index = input[m] - 97;

                if (argv[1][key_index] >= 'A' && argv[1][key_index] <= 'Z')
                {
                    printf("%c", argv[1][key_index] + 32);
                    continue;
                }
                else
                {
                    printf("%c", argv[1][key_index]);
                    continue;
                }
            }

            else    //input not to be changed
            {
                printf("%c", input[m]);
            }
        }
        printf("\n");
        return 0;
    }
}
