#include "lists.h"

/**
 * reverse_listint - Reverses a linked list in place
 * @head: Pointer to the first node in the linked list to reverse
 *
 * Return: Pointer to the first node in the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL, *next;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}

	return (*head = prev);
}
