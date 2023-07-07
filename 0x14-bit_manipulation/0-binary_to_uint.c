#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint: convert a binary number to an unsigned int
 * @b: char var
 * Return: converted decimal number or 0 if there is an unconvertable char
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int converted_number = 0;
	
	if (*b == NULL)
	{
		return (0);
	}

	while (*b != '0')
	{
		if (*b != '0' && *b != '1')
		{
			return(0);
		}
		nb = (nb*2) + *b
	}
	return (nb)
}

