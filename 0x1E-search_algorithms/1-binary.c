#include "search_algos.h"
/**
 * binary_search -Search for a value in a sorted array using binary search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * @value: Value to search for in the array
 *
 * This function performs a binary search on a sorted integer array to find the
 * index of the specified value. If the value is found, the index is returned;
 * otherwise, -1 is returned.
 *
 * Return: If the value is found, the index of the value; otherwise, -1.
 */
int binary_search(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1;
	int mid = 0;
	size_t i;

	while (left <= right)
	{
		printf("Searching in array: ");
		for (i = left; i < right; i++)
			printf("%d, ", array[i]);
		printf("%d\n", array[i]);

		mid = (left + right) / 2;
		if (array[mid] < value)
		{
			left = mid + 1;
		}
		else if (array[mid] > value)
		{
			right = mid - 1;
		}
		else if (mid == value)
		{
			return (mid);
		}
	}
	return (-1);
}

