#include <stdio.h>


void _squeeze(char s1[], char s2[]);

int main()
{
    int i = 0;
    char string[100] = "hello world";
    _squeeze(string, "ole");
    printf("\n%s\n", string);
    return 0;
}

void _squeeze(char s1[], char s2[])
{
    int i, j, k;
    char squeezed_array[100];

    i = j = k = 0;
    while (s1[i] != '\0')
    {
        j = 0;
        while (s2[j] != '\0')
        {
            if (s1[i] == s2[j])
            {
                break;
            }
            j++;
        }
        if (s2[j] == '\0')
        {
            squeezed_array[k++] = s1[i];
        }
        i++;
    }
    i = 0;
    while ((s1[i] = squeezed_array[i]) != '\0')
    {
        i++;
    }
}
