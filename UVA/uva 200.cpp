#include<bits/stdc++.h>

int main ()
{
    char A [5000] [21], Temp[21];
    int I = 0, Len, N, J;
    int L[26] = {0};

    while (scanf("%s", Temp)) { // input taken in Temp

        if (Temp [0] == '#') // break condition
            break;

        Len = strlen (Temp);

        for (J = 0; J < Len; J++) // Array intialized
            A [I] [J] = Temp [J];

        while (J != 21) // avoid garbage value
            A [I] [J++] = 'a';
        I++;
    }

    for (J = 0; J < 21; J++) {

        for (N = 0; N < I; N++) {
            if (A [N] [J] > 64 && A [N] [J] < 91)
                L [ (A [N] [J] - 65) ]++;

            if (L [ ( A [N] [J] - 65) ] == 1)
                printf("%c", A [N] [J]);
        }
    }

    printf("\n");

    return 0;
}