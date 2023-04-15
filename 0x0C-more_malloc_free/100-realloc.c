#include "main.h"
#include <stdlib.h>

/**
 * *_realloc - function that reallocates a memory block
 * @ptr: pointer to the memory previously allocated with a call to malloc
 * @old_size: size, in bytes, of the allocated space for ptr
 * @new_size: size, in bytes of the new memory block
 *
 * Return: ptr when old_size == new_size, otherwise NULL
 */


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		ptr = malloc(new_size);
	if (new_size == old_size)
		return (ptr);
	free(ptr);
	ptr = malloc(new_size);

	return (ptr);
}
