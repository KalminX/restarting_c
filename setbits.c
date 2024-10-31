#include <stdio.h>


unsigned int setbits(
					unsigned int x,
					unsigned int p,
					unsigned int n,
					unsigned int y
				);
/**
  * main - The main function of the program
  *
  * Return: Returns 0 if successful
  */
int main(void)
{
	unsigned int result;

	result = setbits(228, 3, 3, 255);
	printf("\nThe result is: %u\n", result);

	return (0);
}

/**
  * setbits - Sets the bits of x to the leftmost n.
  * to the of y starting at bit p.
  * @x: The number whose bit is to be set.
  * @p: The position in x to start setting the bits from.
  * @n: The number of bits to be set.
  * @y: The number whose last n bits would be considered.
  *
  * Return: Returns the new value with those bits set.
  */
unsigned int setbits(
		unsigned int x,
		unsigned int p,
		unsigned int n,
		unsigned int y
)
{
	unsigned int mask;

	mask = ~(~(~0 << n) << (p + 1 - n)) & x;

	return (mask | (y & (~(~0 << n)) << (p + 1 - n)));
}
