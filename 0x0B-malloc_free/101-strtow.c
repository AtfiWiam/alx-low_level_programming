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
	int len = strlen(str), i, j = 0, k = 0;
	char **words;

	words = malloc(sizeof(char) * 100);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			words[j][k] = '\0';
			j++;
			k = 0;
		}
		else
		{
			words[i] = malloc((i + 2) * sizeof(char));
			words[j][k] = str[i];
			k++;
		}
	}

	return (words);
}
