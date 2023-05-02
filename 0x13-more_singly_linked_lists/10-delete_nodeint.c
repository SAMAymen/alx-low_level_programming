#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: pointer to the first element in the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, or -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int i;

	if (*head == NULL)
	    return (-1);

	if (index == 0)
	{
	    current = *head;
	    *head = current->next;
	    free(current);
	    return (1);
	}

	current = *head;
	for (i = 0; current != NULL && i < index - 1; i++)
	    current = current->next;

	if (current == NULL || current->next == NULL)
	    return (-1);

	temp = current->next;
	current->next = temp->next;
	free(temp);

	return (1);
}
