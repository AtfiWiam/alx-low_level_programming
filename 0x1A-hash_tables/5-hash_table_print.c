#include "hash_tables.h"

/**
 * hash_table_print - function that prints a hash table.
 * @ht: hash table.
 *
 * Return: void, no return.
 */
void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *value;
	unsigned long int index;
	int flag = 0;

	if (ht == NULL)
	{
		return;
	}

	printf("{");
	for (index = 0; index < ht->size; index++)
	{
		if (ht->array[index] != NULL)
		{
			if (flag)
			{
				printf(", ");
			}

			value = ht->array[index];

			while (value != NULL)
			{
				printf("'%s': '%s'", value->key, value->value);
				value = value->next;
				if (value != NULL)
				{
					printf(", ");
				}
			}

			flag = 1;
		}
	}

	printf("}\n");
}

