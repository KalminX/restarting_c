#include <stdio.h>


unsigned getbits(unsigned x, int p, int n);

/**
 * main - The main function
 *
 * Returns: Returns 0 if successful
 */
int main(void)
{
	unsigned number;

	number = 777;

	printf("\nThe bits are: %u.\n", getbits(number, 5, 3));
}

/**
 * getbits - A function used to get specific
 * bits
 * @x: The number whose bits would be found
 * @p: The bit position to start from
 * @n: The number of bits from p
 *
 * Returns: Returns the bits found
 */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p+1-n)) & ~(~0 << n);
}
