#include <stdio.h>


int _len(char string[]);
void _reverse(char s[]);

int main()
{
    int i;
    char c;
    char string[100];
    char reversed_string[100];

    i = 0;
    while ((c = getchar()) != EOF)
    {
        string[i] = c;
        ++i;
    }
    string[i] = '\0';

    _reverse(string);
    printf("\n%s\n", string);
    return 0;
}

void _reverse(char s[])
{
    int i, j, length;
    char reversed[100];

    j = 0;
    length = _len(s) - 1;
    for (i = length; i >= 0; --i)
    {
        reversed[j] = s[i];
        ++j;
    }
    reversed[j] = '\0';

    j = 0;
    for (i = 0; i <= length; ++i)
    {
        s[i] = reversed[i];
    }
}

int _len(char string[])
{
    int i;

    i = 0;
    while (string[i] != '\0')
    {
        ++i;
    }

    return i;
}
