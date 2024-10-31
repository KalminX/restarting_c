#include <stdio.h>


int main()
{
    int nother, nwspace, i, c;

    int digit_array[10];

    nother = nwspace= 0;
    
    
    for (i = 0; i <= 9; ++i)
    {
        digit_array[i] = 0;
    }

    for (i = 0; (c = getchar()) != EOF; ++i)
    {
        if (c >= '0' && c <= '9')
            ++digit_array[c - '0'];
        else if (c == '\n' || c == '\t' || c == ' ')
            ++nwspace;
        else
            ++nother;
    }

    printf("Digits =");
    for (i = 0; i <= 9; ++i)
    {
        printf(" %d", digit_array[i]);
    }
    printf("\n");
    printf("Number of other characters - %d\nNumber of whitespace - %d\n", nother, nwspace);
}
