#include "main.h"

/**
 * _memset - fills memory with a constant byte.
 * @s: memory area pointed to.
 * @b: constant byte.
 * @n: bytes of the memory.
 *
 * Return: pointer to the memory area (s).
 */

char *_memset(char *s, char b, unsigned int n)
{
	char *ptr = s;

	while (n > 0)
	{
		*s = b;
		s++;
		n--;
	}
	return (ptr);
}
