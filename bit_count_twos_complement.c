#include <stdio.h>

unsigned int bit_count(unsigned int number);

/**
  * main - The main function where the program is
  * run
  *
  * Return: Returns 0 if successful
  */
int main(void)
{
	unsigned int result;

	result = bit_count(255);
	printf("\nThe result is: %u\n", result);
}

/**
  * bit_count - A function that returns the number
  * of set bits in a number
  * @number: The number whose bit is to be counted.
  *
  * Return: Returns the number
  */
unsigned int bit_count(unsigned int number)
{
	int i;

	i = 0;
	while (number &= (number - 1))
		++i;
	return (i);
}
