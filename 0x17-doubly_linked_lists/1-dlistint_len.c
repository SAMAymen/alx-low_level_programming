#include "lists.h"
/**
 * dlistint_len - Determines the count of elements in a linked dlistint_t list.
 * @h: The head of the dlistint_t list.
 *
 * Return: Count of elements in the dlistint_t list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
