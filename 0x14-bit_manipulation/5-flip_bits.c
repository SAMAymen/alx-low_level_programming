#include "main.h"

/**
 * flip_bits - Calculates nb of bits to convert one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int diff;
	unsigned int num_flipped = 0, i;

	diff = n ^ m;

	for (i = 0; i < (sizeof(unsigned long int) * 8); i++)
	{
		if (diff & (1ul << i))
			num_flipped++;
	}

	return (num_flipped);
}

