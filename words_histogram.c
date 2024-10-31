#include <stdio.h>
#define IN 1
#define OUT 0

/**
  * main - The main program for my word histogram
  *
  * Returns: Returns 0 on success
  */
int main() {
    int nw, state, w_length, count, i, c, flag, j, max_height;
    int word_array[20];

    state = OUT;
    count = nw = w_length = i = flag = 0;

    for (i = 0; i < 20; ++i)
    {
        word_array[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            flag = 0;
            count = 0;
            state = IN;
        }
        if (state == IN) {
            ++count;
        }
        else if (flag == 0)
        {
           ++word_array[count - 1];
           flag = 1;
        }
    }
    
    max_height = 0;
    for (i = 0; i < 20; ++i)
    {
        if (word_array[i] > max_height)
        {
            max_height = word_array[i]; 
        }
        printf("%d letter counts - %d\n", i + 1, word_array[i]);
    }
    printf("Max height: %d", max_height);

    printf("    |\n|\n|\n");
    for (i = max_height; i > 0; --i)
    {
        printf("%4d--|    ", i);
        for (j = 0; j < 20; ++j)
        {
            if (word_array[j] > i)
            {
                printf("   |----|");
            }
            else
                printf("         ");

        }
        printf("\n");
    }
    printf("   0-----------------------------------------------------------");
    printf("-----------------------------------------------------------");
    printf("-----------------------------------------------------------");
    printf("--------------------------------------------\n");

	return (0);
}

