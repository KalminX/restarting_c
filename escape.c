#include <stdio.h>
#define MAXLINE 1000

void escape(char s[], char t[]);
int main(void)
{
	char c;
	char line[MAXLINE];
	char output[MAXLINE];
	int i;

	i = 0;
	while ((c = getchar()) != EOF)
	{
		line[i] = c;
		++i;
	}

	line[i] = '\0';

	escape(output, line);

	return (0);
}

void escape(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (t[i] != '\0')
	{
		char val;
		switch (t[i])
		{
			case '\t':
				s[j] = '\\';
				s[j + 1] = 't';
				++i;
				j+=2;
				break;
			case '\n':
				s[j] = '\\';
				s[j + 1] = 'n';
				++i;
				j+=2;
				break;
			default:
				s[j] = t[i];
				++i;
				++j;
				break;
		}
	}
	s[j] = '\0';
	printf("\nThe new string is: %s\n", s);
}
