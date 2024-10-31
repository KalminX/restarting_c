#include <stdio.h>
#define MAXLINE 1000


int any(char s1[], char s2[]);

/**
 * main - The main function
 * Return: Returns 0 on success
 */

int main(void)
{
	char line[MAXLINE];
	int i, position;
	char c;

	i = 0;
	while ((c = getchar()) != EOF)
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	position = any("abc", line);
	printf("\nThe position is: %d.\n", position);

	return (0);
}


/**
 * any - a function that finds the position
 * of any character in a string.
 * @s1: the string whose character position is to
 * be found
 * @s2: the string which is being checked.
 *
 * Return: The position of any character it matches
 * in s1.
 */
int any(char s1[], char s2[])
{
	int i, j, position;

	i = j = 0;
	position = -1;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
			{
				position = j;
				break;
			}
			++j;
		}
		if (s1[i] == s2[j])
			break;
		++i;
	}
	return (position);
}
