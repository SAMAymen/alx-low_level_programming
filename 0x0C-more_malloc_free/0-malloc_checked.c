#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - function that allocates memory using malloc
 * @b: size/number of bytes to be allocated
 *
 * Return: returns a pointer to allocated memory
 */

void *malloc_checked(unsigned int b)
{
	void *p;

	p = (void *) malloc(b);
	if (p == NULL)
	{
		exit(98);
	}
	return (p);
}
