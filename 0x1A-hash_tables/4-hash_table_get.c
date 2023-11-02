#include "hash_tables.h"

/**
 * hash_table_get - function that retrieves a value associated with a key.
 * @ht: hash table to look into.
 * @key: key value to look for.
 *
 * Return: the value associated with the element,
 * or NULL if key couldn’t be found.
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *value;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
	{
		return (NULL);
	}

	index = key_index((const unsigned char *)key, ht->size);

	if (index >= ht->size)
	{
		return (NULL);
	}

	value = ht->array[index];

	while (value && strcmp(value->key, key) != 0)
	{
		value = value->next;
	}

	if (value == NULL)
	{
		return (NULL);
	}

	return (value->value);
}

