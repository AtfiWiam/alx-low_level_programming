#include "main.h"

/**
 * reverse_array - function that reverses the content
 * of an array of integers.
 * @a: array of integers
 * @n: number of elements of the array.
 *
 * Return: nothing.
 */

void reverse_array(int *a, int n)
{
	int rev, i, j;

	for (i = 0, j = n - 1; i < j; i++, j--)
	{
		rev = a[i];
		a[i] = a[j];
		a[j] = rev;
	}
}
