#include "lists.h"

/**
 * get_dnodeint_at_index - Retrieves a node within a dlistint_t list.
 * @head: The head of the dlistint_t list.
 * @index: The targeted node index.
 *
 * Return: If the node is not found - NULL.
 *         Otherwise - the address of the located node .
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	for (; index != 0; index--)
	{
		if (head == NULL)
			return (NULL);
		head = head->next;
	}

	return (head);
}
