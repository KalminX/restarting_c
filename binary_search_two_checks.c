#include <stdio.h>

int binsearch(int x, int v[], int n);
int main(void)
{
	int result;
	int numbers[100] = {2, 4, 6, 8, 10};

	result = binsearch(4, numbers, 5);

	printf("\nThe result is: %d\n", result);
	return (0);
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid + 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return (mid);
	}
	return (-1);
}
