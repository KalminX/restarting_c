#include <stdio.h>

unsigned int invert(unsigned int x, unsigned int p, unsigned int n);

/**
  * main - The main function of the program
  *
  * Return: Returns 0 if successful
  */
int main(void)
{
	unsigned int result;

	result = invert(228, 3, 2);
	printf("\nThe result is: %u\n", result);
	return (0);
}

/**
  * invert - a function that inverts n bits of an
  * unsigned integer x starting from p
  * @x: The number whose bits would be invertec
  * @p: The starting position of inversion
  * @n: The number of bits to be inverted
  *
  * Return: Returns the new integer with bits
  * inverted.
  */
unsigned int invert(
	unsigned int x,
	unsigned int p,
	unsigned int n
)
{
	unsigned int mask;

	mask = ((1U << n) - 1) << p;
	return (x ^ mask);
}
