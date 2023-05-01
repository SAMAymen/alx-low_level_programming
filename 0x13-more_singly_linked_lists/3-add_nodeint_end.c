#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end
 * @head: pointer to the first node
 * @n: element to add
 *
 * Return: address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		listint_t *temp = *head;

		while (temp->next != NULL)
			temp = temp->next;

		temp->next = new;
	}

	return (new);
}
