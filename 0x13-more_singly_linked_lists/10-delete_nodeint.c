#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node at a given index in a linked list
 * @head: Pointer to the first element of the linked list
 * @index: Index of the node to delete (starting from 0)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head, *current = NULL;
	unsigned int i;

	if (*head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	for (i = 0; i < index - 1 && temp != NULL; i++)
		temp = temp->next;

	if (temp == NULL || temp->next == NULL)
		return (-1);

	current = temp->next;
	temp->next = current->next;
	free(current);

	return (1);
}
