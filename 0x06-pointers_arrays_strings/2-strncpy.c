#include "main.h"
/**
 * _strncpy - function that copies a string.
 * @dest: destination.
 * @src: source.
 * @n: bytes from src.
 *
 * Return: pointer to dest.
 */

char *_strncpy(char *dest, char *src, int n)
{
	char *ptr = dest;

	while (n > 0 && *src)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	while (n > 0)
	{
		*dest = '\0';
		dest++;
		n--;
	}
	return (ptr);
}
