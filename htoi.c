#include <stdio.h>

#define MAXLINE 1000

int htoi(char s[]);
int _strlen(char s[]);
int _pow(int base, int index);
int is_abcdef(char c);

int main()
{
    int i, result;
    char c;
    char line[MAXLINE];

    result = 0;
    i = 0;
    while ((c = getchar()) != EOF)
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    result = htoi(line);
    return 0;
}

int htoi(char s[])
{
    int i, len, result, number;


    i = result = 0;
    len = _strlen(s) - 1;

    if (s[i] == '0' && (s[i + 1] == 'x' || s[i] == 'X'))
    {
        i += 2;
        len -= 2;
    }

    while (s[i] != '\0')
    {
        number = is_abcdef(s[i]);
        if (number == -1)
            break;
        result = result + (number * _pow(16, len));
        ++i;
        --len;
    }
    if (number != -1)
        printf("\nThis is the hex value: %d\n", result);
    return result;
}

int is_abcdef(char c)
{
    int value = 0;

    switch (c)
    {
        case 'a': case 'A':
            value = 10;
            break;
        case 'b': case 'B':
            value = 11;
            break;
        case 'c': case 'C':
            value = 12;
            break;
        case 'd': case 'D':
            value = 13;
            break;
        case 'e': case 'E':
            value = 14;
            break;
        case 'f': case 'F':
            value = 15;
            break;
        default:
            if (c >= '0' && c <= '9')
                value = c - '0';
            else
            {
                value = -1;
                printf("\nEnter a valid hex.\n");
            }
            break;
    }

    return value;
}

int _pow(int base, int index)
{
    int result;
    
    result = 1;
    while (index > 0)
    {
        result = result * base;
        --index;
    }

    return result;
}

int _strlen(char s[])
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}


