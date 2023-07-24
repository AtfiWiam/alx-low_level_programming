#include "main.h"
#include <stdio.h>

/**
 * _strcpy - function that copies the string pointed to by src
 * @dest: destination.
 * @src: source.
 * Return: dest.
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;

	while (l >= 0)
	{
		*(dest + l) = *(src + l);

		if (*(src + l) == '\0')
		{
			break;
		}
		l++;
	}

	return (dest);
}

