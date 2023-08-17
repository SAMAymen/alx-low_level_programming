#include "lists.h"

/**
 * insert_dnodeint_at_index - Adds a fresh node to a dlistint_t
 *                            list at a specified position.
 * @h: A pointer to the head of the dlistint_t list.
 * @idx: The index at which the new node should be inserted.
 * @n: The integer value to be held by the new node.
 *
 * Return: If the operation is unsuccessful - NULL.
 *         Otherwise - the address of the new node.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *tmp = *h, *new;

	if (idx == 0)
		return (add_dnodeint(h, n));

	for (; idx != 1; idx--)
	{
		tmp = tmp->next;
		if (tmp == NULL)
			return (NULL);
	}

	if (tmp->next == NULL)
		return (add_dnodeint_end(h, n));

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = tmp;
	new->next = tmp->next;
	tmp->next->prev = new;
	tmp->next = new;

	return (new);
}
