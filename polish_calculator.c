#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <string.h>
#include <ctype.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

void swap_top(void);
int getop(char []);
void print_top(void);
void push(double);
double pop(void);
void duplicate(void);

int num;
/* reverse Polish calculator */
int main() {
    int type;
    double op2, op1;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
			case '%':
				op2 = pop();
				op1 = pop();
				if (op2 != 0.0)
					push((double)((int)op1 % (int)op2));
				else
					printf("error: zero division\n");
				break;
			case 't':
				print_top();
				break;
			case 's':
				swap_top();
				break;
			case 'd':
				duplicate();
				break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}


#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* swap: swaps the top elements */
void swap_top(void)
{
	val[sp] = val[sp - 1];
	val[sp - 1] = num;
}

/* print_top: prints the top element of the stack. */
void print_top(void)
{
	printf("\nThe top of the stack is: %d\n", num);
}

/* duplicate: duplicate the topmost element */
void duplicate(void)
{
	if (sp > 0)
		push(val[sp]);
	sp++;
}

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
	num = val[sp];
    if (sp > 0)
	{
		printf("\nThe value is %lf\n", val[sp - 1]);
        return val[--sp];
	}
    else
	{
        printf("error: stack empty\n");
        return 0;
    }
}


#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[]) {
    int i, c;

    // Skip whitespace characters
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */

    i = 0;
    // Collect integer part
    if (isdigit(c) || c == '-') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    // Collect fraction part
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);

    return NUMBER;
}


#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

/* getch: get a (possibly pushed-back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

