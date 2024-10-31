#include <stdio.h>

int strindex(char s[], char t[]);

int main()
{
	int result;

	result = strindex("how is cali, cali, call", "cal");
	printf("\nThe result is: %d\n", result);
	return (0);
}

int strindex(char s[], char t[])
{
	int i, j, k, index;
	
	index = -1;
	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			index = i;
	}
	return index;
}
