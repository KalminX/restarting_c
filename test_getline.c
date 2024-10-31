#include <stdio.h>

#define MAXLINE 1000

int _getline(char line[], int lim);
void copy(char to[], char from[]);


int main()
{
    int max, i;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    printf("The lines greater than 80 are:\n");
    while ((i = _getline(line, MAXLINE)) > 0 )
    {
        if (i > max)
        {
            max = i;
            copy(longest, line);
        }
        if (i > 80)
        {
            printf("\t\t%s\n", line);
        }
    }

    if (max > 0)
        printf("The longest line is: %s with a length of %d.\n", longest, max);
    else
        printf("Enter a line\n");

    return 0;
}

int _getline(char line[], int lim)
{
    int c, i, flag;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    while (i > 0 && (line[i - 1] == ' ' || line[i - 1] == '\t'))
    {
        --i;
        line[i] = '\0';
    }
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
