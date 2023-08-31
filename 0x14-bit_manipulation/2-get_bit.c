#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index
 * @n: The number from which to extract the bit
 * @index: The index of the bit to be extracted
 * Return: The value of the bit at the given index,
 * or -1 if an error occurred
 */

int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);
	return ((n >> index) & 1);
}
