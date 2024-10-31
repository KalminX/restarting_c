#include <stdio.h>


int main()
{
	char c;
	int bl_count, tb_count, nl_count;

	bl_count = tb_count = nl_count = 0;
	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
			nl_count++;

	}

	printf("\n  bl_count: %d, tb_count: %d \n", bl_count, tb_count);
	return (0);
}
