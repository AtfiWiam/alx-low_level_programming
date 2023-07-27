#include "main.h"

/**
 * rot13 - function that encodes a string using rot13.
 * @str: string.
 *
 * Return: pointer to str.
 */

char *rot13(char *str)
{
	char *ptr = str;
	char alph[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot_13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	int index;

	while (*str)
	{
		index = 0;

		while (alph[index] != '\0')
		{
			if (*str == alph[index])
			{
				*str = rot_13[index];
				break;
			}
			index++;
		}
		str++;
	}
	return (ptr);
}
