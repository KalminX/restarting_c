#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, nw, nc, nl, state;

    nw = nc = nl = 0;

    state = OUT;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == 10)
            ++nl;
        if (c == 32 || c == 9 || c == 10) {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
            putchar(c);
        }
        putchar(c);
    }
    printf("\nword count - %d \ncharacter count - %d \nline count - %d\n", nw, nc, nl);
    return 0;
}
