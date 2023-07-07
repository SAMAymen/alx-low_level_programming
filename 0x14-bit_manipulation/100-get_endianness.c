#include "main.h"

/**
 * get_endianness - Determines the endianness of the machine.
 * Return: 0 if the machine is big-endian, 1 if it is little-endian.
 */
int get_endianness(void)
{
	int i = 1;
	char *c = (char *)&i;

	return (*c);
}

