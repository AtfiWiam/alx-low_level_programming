#include "lists.h"

/**
 * free_listint_ptrs2 - function that frees a listint_t list.
 * @head: pointer to the first and new node in the list.
 *
 * Return: nothing
 */

void free_listint_ptrs2(listptr_t **head)
{
	listptr_t *current, *temp;

	if (head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * free_listint_safe - function that frees a listint_t list.
 * @h: double pointer to the first node in the list.
 *
 * Return: the size of the list that was freed.
 */

size_t free_listint_safe(listint_t **h)
{
	listptr_t *loop_tracker, *tracker_head, *tracker_node;
	size_t num_nodes_freed = 0;
	listint_t *current_node;

	tracker_head = NULL;

	while (*h != NULL)
	{
		loop_tracker = malloc(sizeof(listptr_t));

		if (loop_tracker == NULL)
			exit(98);
		loop_tracker->ptr = (void *)*h;
		loop_tracker->next = tracker_head;
		tracker_head = loop_tracker;
		tracker_node = tracker_head;

		while (tracker_node->next != NULL)
		{
			tracker_node = tracker_node->next;
			if (*h == tracker_node->ptr)
			{
				*h = NULL;
				free_listint_ptrs2(&tracker_head);
				return (num_nodes_freed);
			}
		}
		current_node = *h;
		*h = (*h)->next;
		free(current_node);
		num_nodes_freed++;
	}
	*h = NULL;
	free_listint_ptrs2(&tracker_head);
	return (num_nodes_freed);
}
