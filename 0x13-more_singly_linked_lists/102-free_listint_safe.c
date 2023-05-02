#include "lists.h"

/**
 * free_listint_safe - It Frees a linked list
 * @h: Pointer to first node in the linked list
 *
 * Return: The number of elements in the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current = NULL, *next = NULL;

	if (h == NULL || *h == NULL)
		return (count);

	current = *h;
	while (current != NULL)
	{
		next = current->next;
		count++;

		current->n = 0xDEADBEEF;
		current->next = NULL;
		current = next;

		if (current == *h)
		{
			*h = NULL;
			return (count);
		}
	}

	while (*h != NULL)
	{
		current = *h;
		*h = current->next;
		free(current);
		count++;
	}

	return (count);
}
