#include "main.h"

/**
 * _memcpy - copies memory area.
 * @dest: destination to memory area.
 * @src: source of memory area.
 * @n: bytes from memory area.
 *
 * Return: pointer to (dest).
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *ptr = dest;

	while (n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	return (ptr);
}
