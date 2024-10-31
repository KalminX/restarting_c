#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

double atof(char s[]);

int main()
{
	char line[MAXLINE];
	double result;

	result = atof(".55e-2");
	printf("\nThe result is: %lf\n", result);
	return (0);
}

double atof(char s[])
{
	double val, power;
	int i, j, sign;

	for (i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		printf("\nThe value of s[i] is %c\n", s[i]);
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if (s[i] == 'e' || s[i] == 'E')
	{
		i++;
		if (s[i] == '-')
		{
			i++;
			for (j = 0; j < (s[i] - '0'); j++)
				power *= 10;
		}
		else
		{
			if (s[i] == '+')
				i++;
			for (j = 0; j < (s[i] - '0'); j++)
				power /= 10;
		}
	}
	return sign * val / power;
}
