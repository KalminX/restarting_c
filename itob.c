#include <stdio.h>

void itob(int n, char s[], int b);
int _strlen(char s[]);
void reverse(char s[]);
int main()
{
	char convert[100];

	itob(245, convert, 13);
	return (0);
}

void itob(int n, char s[], int b)
{
	int i = 0;
	char c;
	
	if (b >= 10)
	{
		while (n != 0)
		{
			c = n % b;
			switch (c)
			{
				case 15:
					c = 'F';
					break;
				case 14:
					c = 'E';
					break;
				case 13:
					c = 'D';
					break;
				case 12:
					c = 'C';
					break;
				case 11:
					c = 'B';
					break;
				case 10:
					c = 'A';
					break;
				default:
					c = n % b + '0';
					break;
			}
			n/=b;
			s[i++] = c;
		}
	}
	else
	{
		while (n != 0)
		{
			s[i++] = n % b + '0';
			n/=b;
		}
	}
	s[i] = '\0';
	reverse(s);
	printf("\nThe value of s is: %s\n", s);
}

void reverse(char s[])
{
	int len = _strlen(s) - 1;
	int n = len / 2 + 1;
	int i = 0;
	char c;

	while (i < n)
	{
		c = s[i];
		s[i] = s[len];
		s[len] = c;
		i++;
	}
}

int _strlen(char s[])
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	printf("\nThe length of the string is: %d\n", i);
	return (i);
}
