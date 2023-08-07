#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * strtow - splits a string into words.
 * @str: string.
 *
 * Return: pointer of an array.
 */
char **strtow(char *str)
{
	int lenght = strlen(str), i, j = 0, k = 0;
	char **split;

	split = malloc(sizeof(char) * 100);

	for (i = 0; i <= lenght; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			split[j][k] = '\0';
			j++;
			k = 0;
		}
		else
		{
			split[i] = malloc((i + 2) * sizeof(char));
			split[j][k] = str[i];
			k++;
		}
	}

	return (split);
}
