#include "lists.h"

/**
 * print_listint - prints all elements of a list
 * @h: pointer to the first element of the list
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t nodeCount = 0;
	if (h == NULL)
		return (0);
	for (; h != NULL; h = h->next, nodeCount++)
		printf("%d\n", h->n);
	return (nodeCount);
}
