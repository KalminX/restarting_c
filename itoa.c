#include <stdio.h>

int _strlen(char s[]);
void itoa(int n, char s[], int width);
void reverse(char s[]);
int main()
{
	char string[1000];

	itoa(6000772, string, 29);
	printf("\nThe string is: (start)%s(stop)\n", string);
}

void itoa(int n, char s[], int width)
{
	int i = 0;
	int sign;
	int len;

	if ((sign = n) < 0)
		n = -n;

	do
	{
		s[i++] = n % 10 + '0';
	}while((n /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';
	len = i;
	while (len < width)
	{
		s[i] = ' ';
		width--;
		++i;
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int i, j, len;
	char c;

	i = 0;
	len = j = _strlen(s) - 1;

	while (i < len)
	{
		c = s[i];
		s[i] = s[len];
		s[len] = c;
		i++;
		len--;
	}
	s[j + 1] = '\0';
}

int _strlen(char s[])
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return i;
}
