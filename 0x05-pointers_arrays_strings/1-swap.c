#include "main.h"

/**
 * swap_int - C function that swaps the values of two integers.
 * @a: integer value.
 * @b: integer value.
 *
 * Return: void, no return.
 */
void swap_int(int *a, int *b)
{
	int swap = *a;

	*a = *b;
	*b = swap;

}
