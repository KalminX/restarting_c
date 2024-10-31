#include <stdio.h>

#define MAXLINE 1000

void _de_comment(char code[]);
int main()
{
    int i;
    char c;
    char c_code[MAXLINE];

    i = 0;
    while ((c = getchar()) != EOF)
    {
        c_code[i] = c;
        ++i;
    }
    c_code[i] = '\0';

    printf("\nOld code: %s\n", c_code);
    _de_comment(c_code);

    printf("\nNew code: %s\n", c_code);
    return 0;
}

void _de_comment(char code[])
{
    char new_code[MAXLINE];
    int i;
    int j;

    i = j = 0;
    while (code[i] != '\0')
    {
        if ((code[i] == '/' && code[i + 1] == '*') || (code[i] == '*' && code[i + 1] == '/'))
         {
            i = i + 2;
            continue;
        }
        new_code[j] = code[i];
        ++i;
        ++j;
    }
    new_code[j] = '\0';
    
    i = 0;
    while (new_code[i] != '\0')
    {
        code[i] = new_code[i];
        ++i;
    }
    code[i] = '\0';
}
