#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node in a linked list
 * @head: pointer to first node
 * @index: index of the node to return (starting from 0)
 *
 * Return: pointer to the desired node or NULL if not found
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	for (i = 0; head != NULL && i < index; i++)
		head = head->next;

	return (head);
}
