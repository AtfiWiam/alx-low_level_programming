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
	size_t count = 0;
	listptr_t *head_ptrs, *curr_ptr;
	listint_t *temp;

	head_ptrs = NULL;
	while (*h != NULL)
	{
		curr_ptr = head_ptrs;

		while (curr_ptr != NULL)
		{
			if (*h == curr_ptr->ptr)
			{
				*h = NULL;
				free_listint_ptrs2(&head_ptrs);
				return (count);
			}
			curr_ptr = curr_ptr->next;
		}
		temp = *h;
		*h = (*h)->next;
		temp->next = NULL;
		free(temp);
		count++;
	}
	free_listint_ptrs2(&head_ptrs);
	return (count);
}
