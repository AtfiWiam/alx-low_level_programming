#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * array_range - creates an array of integers.
 * @min: minimum value.
 * @max: maximum value.
 *
 * Return: pointer to the newly created array,
 * NULL if man > mix or if malloc fails
 */

int *array_range(int min, int max)
{
	int *arr, i;

	if (min > max)
		return (NULL);

	arr = (int *)malloc((max - min + 1) * sizeof(int));

	if (arr == NULL)
		return (NULL);
	for (i = 0; min <= max; ++i, ++min)
	{
		arr[i] = min;
	}
	return (arr);
}
