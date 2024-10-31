#include <stdio.h>

/**
* A function that finds the power of a base
*/

int power(int base, int n);


int main()
{
    int i, n, result;

    i = result = 0;
    n = 2;

    for (i = 1; i <= 10; ++i )
    {
        result = power(n, i);
        printf("%d", result);
        putchar(10);
    }

    return 0;
}

int power(int base, int n)
{
    int i, result;
    
    result = base;
    for (i = 1; i <= n; ++i)
    {
        result = result * base;
    }

    return result;
}
