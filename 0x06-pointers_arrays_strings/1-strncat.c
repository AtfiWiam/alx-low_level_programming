#include "main.h"

/**
 * _strncat - function that concatenates two strings.
 * @src: source.
 * @dest: destination.
 * @n: bytes from source
 * Return: pointer to dest.
 */

char *_strncat(char *dest, char *src, int n)
{
	char *ptr = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src && n > 0)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
	return (ptr);
}
