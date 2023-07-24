#include "main.h"

/**
 * swap_int - C function that swaps the values of two integers.
 * @i: integer value.
 * @j: integer value.
 *
 * Return: void, no return.
 */
void swap_int(int *i, int *j)
{
	int swap = *i;

	*i = *j;
	*j = swap;

}
