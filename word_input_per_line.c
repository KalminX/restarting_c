#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c, nw, nc, nl, state, flag;

    nw = nc = nl = flag = 0;

    state = OUT;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == 10)
            ++nl;
        if (c == 32 || c == 9 || c == 10) {
            state = OUT;
            if (flag)
                putchar(10);
            flag = 0;
        }
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
        if (state == IN) {
            flag = 1;
            putchar(c);
        }
    }
    return 0;
}
