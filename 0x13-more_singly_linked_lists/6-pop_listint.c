#include "lists.h"

/**
 * pop_listint - delete the head node and return its data
 * @head: pointer to the first node
 *
 * Return: the head node's data(n)
 */
int pop_listint(listint_t **head)
{
	if (*head == NULL)
		return (0);

	listint_t *temp = *head;
	int data = temp->n;

	*head = temp->next;
	free(temp);

	return (data);
}
