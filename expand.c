#include <stdio.h>


#define MAXLINE 1000


void expand(char s1[], char s2[]);
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

	expand(line, output);
	return (0);
}

void expand(char s1[], char s2[])
{
	int i, j, k;
	char c;
	char value[MAXLINE];

	i = j = k = 0;
	putchar(10);
	while (s1[i] != '\0')
	{
		if ((s1[i] >= 'a' && s1[i] <= 'z') && s1[i + 1] == '-' && (s1[i + 2] <= 'z' && s1[i + 2] >= 'a'))
		{
			k = 0;
			while (s1[i] >= 'a' || s1[i + 2] <= 'z')
			{
				c = s1[i] + k;
				if (c > s1[i + 2])
				{
					++i;
					break;
				}
				value[j] = s1[i] + k;
				putchar(value[j]);
				++j;
				++k;
			}
			i+=1;
		}
		else if ((s1[i] >= 'A' && s1[i] <= 'Z') && s1[i + 1] == '-' && (s1[i + 2] >= 'A' && s1[i + 2] <= 'Z'))
		{
			k = 0;
			while (s1[i] >= 'A' || s1[i + 2] <= 'Z')
			{
				c = s1[i] + k;
				if (c > s1[i + 2])
				{
					++i;
					break;
				}
				value[j] = s1[i] + k;
				putchar(value[j]);
				++j;
				++k;
			}
			i+=1;
		}
		else if ((s1[i] >= '0' && s1[i] <= '9') && s1[i + 1] == '-' && (s1[i + 2] <= '9' && s1[i + 2] >= '0'))
		{
			k = 0;
			while (s1[i] >= '0' || s1[i + 2] <= '9')
			{
				c = s1[i] + k;
				if (c > s1[i + 2])
				{
					break;
				}
				value[j] = c;
				putchar(value[j]);
				++j;
				++k;
			}
			i+=1;
		}
		else
		{
			value[j] = s1[i];
			++j;
		}
		++i;
	}
	++j;
	value[j] = '\0';
	printf("\nThe value: %s\n", value);
}
