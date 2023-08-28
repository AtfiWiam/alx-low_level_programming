#include "lists.h"

/**
 * free_listint_ptrs - function that frees a listint_t list.
 * @head: pointer to the first and new node in the list.
 *
 * Return: nothing
 */

void free_listint_ptrs(listptr_t **head)
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
 * print_listint_safe - function that prints a listint_t linked list.
 * @head: pointer to the first and new node in the list.
 *
 * Return: number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	listptr_t *new_ptr, *head_ptrs, *curr_ptr;

	head_ptrs = NULL;
	while (head != NULL)
	{
		new_ptr = malloc(sizeof(listptr_t));
		if (new_ptr == NULL)
			exit(98);
		new_ptr->ptr = (void *)head;
		new_ptr->next = head_ptrs;
		head_ptrs = new_ptr;
		curr_ptr = head_ptrs;

		while (curr_ptr->next != NULL)
		{
			curr_ptr = curr_ptr->next;
			if (head == curr_ptr->ptr)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free_listint_ptrs(&head_ptrs);
				return (count);
			}
		}
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		count++;
	}
	free_listint_ptrs(&head_ptrs);
	return (count);
}
