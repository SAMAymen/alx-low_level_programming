#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list.
 *
 * @head: A pointer to the head node of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t num_nodes = 0;
	const listint_t *current = head;
	const listint_t **ptrs = malloc(sizeof(listint_t *) * 1024);

	if (!ptrs)
		exit(98);

	while (current)
	{
		size_t i;

		for (i = 0; i < num_nodes; i++)
		{
			if (ptrs[i] == current)
			{
				printf("-> [%p] %d\n", (void *)current, current->n);
				free(ptrs);
				return (num_nodes);
			}
		}

		ptrs[num_nodes++] = current;
		if (num_nodes >= 1024)
			break;

		printf("[%p] %d\n", (void *)current, current->n);
		current = current->next;
	}

	free(ptrs);
	return (num_nodes);
}
