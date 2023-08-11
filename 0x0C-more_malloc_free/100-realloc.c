#include "main.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * _realloc - reallocates a memory block using malloc and free.
 * @ptr: pointer to the memory previously allocated.
 * @old_size: size, in bytes, of ptr allocated space.
 * @new_size: new size, in bytes, of the new memory block.
 *
 * Return: pointer to the new allocated memory,
 * if new_size == old_size, returns the previous pointer to the memory.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	unsigned int min_size;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size == old_size)
		return (NULL);

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
		return (NULL);

	min_size = (old_size < new_size) ? old_size : new_size;

	memcpy(new_ptr, ptr, min_size);
	free(ptr);

	return (new_ptr);
}
