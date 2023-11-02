#include "hash_tables.h"

/**
 * hash_table_delete - function that deletes a hash table.
 * @ht: hash table.
 *
 * Return: void, no return.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *node, *temp;
	unsigned long int index = 0;

	while (index < ht->size)
	{
		if (ht->array[index] != NULL)
		{
			node = ht->array[index];
			while (node != NULL)
			{
				temp = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = temp;
			}
		}
		index++;
	}

	free(ht->array);
	free(ht);
}

