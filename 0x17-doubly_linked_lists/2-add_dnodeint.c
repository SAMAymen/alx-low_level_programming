#include "lists.h"
/**
 * add_dnodeint - Inserts a fresh node at the start of a dlistint_t list.
 * @head: A pointer to the head of the dlistint_t list .
 * @n: The integer to be held by the new node.
 *
 * Return: If the operation is unsuccessful - NULL.
 *		 Otherwise - the address of the new node .
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;

	return (new);
}
