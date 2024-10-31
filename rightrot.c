#include <stdio.h>


unsigned int rightrot(unsigned int x, unsigned int n);
int bit_length(unsigned int number);
/**
  * main - The main function of this program
  *
  * Return: Returns 0 if successful
  */
int main(void)
{
	unsigned int result;

	result = rightrot(237, 3);
	printf("\nThe result is: %u\n", result);
	return (0);
}

/**
  * rightrot - A function that rotates a number
  * by n bits to the right.
  * @x: The number to be rotated.
  * @n: The number of bits to be rotated
  *
  * Return: Returns the new value with the number
  * of bits rotated.
  */
unsigned int rightrot(unsigned int x, unsigned int n)
{
	int length, shift, result;
	unsigned int right, left;

	length = bit_length(x);
	n = n % length;
	shift = length - n;
	right = x >> n;
	left = (x << shift) & ((1U << length) - 1);
	result = right | left;

	printf("\nThe right is: %u and the left is %u.\n", right, left);
	return (result);
}

/**
  * bit_length - A function that calculates the
  * number of bits in a number
  * @number: The number whose bits is to be
  * calculated
  *
  * Return: Returns the number of bits in
  * the number.
  */
int bit_length(unsigned int number)
{
	int i;

	i = 1;
	while (number = (number >> 1))
		++i;
	printf("\n%d\n", i);
	return (i);
}
