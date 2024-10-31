#include <stdio.h>
#define MAX_LINE 1000
#define TAB_SIZE 4


void _detab(char line[]);
void tab_exists(char line[]);

int main()
{
    int i;
    char c;
    char line[MAX_LINE];


    i = 0;
    while ((c = getchar()) != EOF)
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    tab_exists(line);

    _entab(line);

    tab_exists(line);
    printf("\nDone\n");
}

void tab_exists(char line[])
{
    int i;

    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] == '\t')
        {
            printf("\nTab located\n");
            return;
        }
        ++i;
    }

    printf("\nNo tab.\n");

}
   
void _detab(char line[])
{
    char tabbed_line[MAX_LINE];
    int i, k, l;
    
    i = 0;
    l = 0;
    while (line[i] != '\0' && l < MAX_LINE - 1)
    {
        printf("%d", l);
        if (line[i] == '\t')
        {
            for (k = 0; k < TAB_SIZE && l < MAX_LINE - 1; ++k)
                tabbed_line[l++] = ' ';
        }
        else
            tabbed_line[l++] = line[i];
        ++i;
    }
    tabbed_line[l] = '\0';

    i = 0;

    printf("\nThe tabbed output:\n");
    while (tabbed_line[i] != '\0')
    {
        line[i] = tabbed_line[i];
        ++i;
    }
    printf("\nEnd of tabbed output.\n");
    line[i] = '\0';

    printf("%s\n", tabbed_line);
}
