#include <stddef.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL.
 * @head: A pointer to a pointer to the head of the list to be freed.
 * Return : Nothing
 */

void free_listint2(listint_t **head)
{
	listint_t *current = *head;
	listint_t *next;

	if (head == NULL)
		return;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}
