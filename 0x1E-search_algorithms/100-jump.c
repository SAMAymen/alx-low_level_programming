#include "search_algos.h"
/**
  * jump_search - Searches for a value in a sorted array
  *               of integers using jump search.
  * @array: A pointer to the first element of the array to search.
  * @size: The number of elements in the array.
  * @value: The value to search for.
  *
  * Return: If the value is not present or the array is NULL, -1.
  *         Otherwise, the first index where the value is located.
  *
  */
int jump_search(int *array, size_t size, int value)
{
	size_t i, saut, step;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);


	for (i = saut = 0; saut < size && array[saut] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", saut, array[saut]);
		i = saut;
		saut += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, saut);

	saut = saut < size - 1 ? saut : size - 1;
	for (; i < saut && array[i] < value; i++)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
	printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	return (array[i] == value ? (int)i : -1);
}
