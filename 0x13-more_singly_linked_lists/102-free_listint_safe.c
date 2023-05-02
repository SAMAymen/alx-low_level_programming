#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: A pointer to a pointer to the head node of the list.
 *
 * Return: The number of nodes freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *next;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	*h = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = NULL;

		if (current < next)
		{
			free(current);
			count++;
		}
		else
		{
			*h = current;
			break;
		}

		current = next;
	}

	return (count);
}
