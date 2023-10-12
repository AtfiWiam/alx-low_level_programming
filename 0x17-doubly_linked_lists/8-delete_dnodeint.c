#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes a node at a specific index
 * @head: double pointer to the linked list
 * @index: index at which to delete node
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current_node;
	unsigned int a;

	if (head == NULL || *head == NULL)
		return (-1);
	current_node = *head;
	if (index == 0)
	{
		*head = current_node->next;
		if (current_node->next != NULL)
		{
			current_node->next->prev = NULL;
		}
		free(current_node);
		return (1);
	}
	for (a = 0; a < index; a++)
	{
		if (current_node->next == NULL)
			return (-1);
		current_node = current_node->next;
	}
	current_node->prev->next = current_node->next;
	if (current_node->next != NULL)
		current_node->next->prev = current_node->prev;
	free(current_node);
	return (1);
}
