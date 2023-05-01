#include "lists.h"

/**
 * free_listint2 - free list and set head to NULL
 * @head: pointer to the first node
 *
 * Return: Nothing
 */
void free_listint2(listint_t **head)
{
	if (head != NULL)
	{
		while (*head != NULL)
		{
			listint_t *temp = *head;

			*head = (*head)->next;
			free(temp);
		}
	}
}
