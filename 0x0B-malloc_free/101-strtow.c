#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>


/**
 * count_words - count the number of words in the input string.
 * @str: string.
 *
 * Return: number of words.
 */
int count_words(char *str)
{
	int count = 0;
	int is_word = 0;

	while (*str)
	{
		if (*str != ' ' && !is_word)
		{
			is_word = 1;
			count++;
		}
		else if (*str == ' ')
		{
			is_word = 0;
		}
		str++;
	}
	return (count);
}

/**
 * strtow - splits a string into words.
 * @str: string.
 *
 * Return: pointer of an array.
 */
char **strtow(char *str)
{
	int wc = count_words(str), wi = 0, wl = 0, iw = 0, i, j;
	char **w = (char **)malloc((wc + 1) * sizeof(char *));

	if (!str || !*str) 
		return (NULL);
	if (!w) 
		return (NULL);
	for (i = 0; str[i]; ++i)
	{
		if (str[i] != ' ')
		{
			if (!iw) 
				iw = wl = 1;
			else wl++;
		}
		else if (iw)
		{
			w[wi] = (char *)malloc((wl + 1) * sizeof(char));
			if (!w[wi])
			{
				for (j = 0; j < wi; ++j) 
					free(w[j]);
				free(w);
				return (NULL);
			}
			strncpy(w[wi], str + i - wl, wl);
			w[wi++][wl] = iw = 0;
		}
	}
	if (iw)
	{
		w[wi] = (char *)malloc((wl + 1) * sizeof(char));
		if (!w[wi])
		{
			for (j = 0; j < wi; ++j) 
				free(w[j]);
			free(w);
			return (NULL);
		}
		strncpy(w[wi], str + strlen(str) - wl, wl);
		w[wi][wl] = 0;
	}
	w[wi] = NULL;
	return (w);
}
