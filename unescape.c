#include <stdio.h>
#define MAXLINE 1000

void unescape(char s[], char t[]);
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

	unescape(output, line);

	return (0);
}

void unescape(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (t[i] != '\0')
	{
		if (t[i] == '\\')
		{
			++i;
			switch (t[i])
			{
				case 't':
					s[j] = '\t';
					++i;
					++j;
					break;
				case 'n':
					s[j] = '\n';
					++i;
					++j;
					break;
				default:
					break;
			}
		}
		else
		{
			s[j] = t[i];
			++j;
			++i;
		}
	}
	s[j] = '\0';
	printf("\nThe new string is: %s\n", s);
}
