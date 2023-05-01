#include "lists.h"

/**
 * free_listint - free list
 * @head: pointer to the first node
 *
 * Return: Nothing
 */
void free_listint(listint_t *head)
{
	while (head != NULL)
	{
		listint_t *temp = head;

		head = head->next;
		free(temp);
	}
}
