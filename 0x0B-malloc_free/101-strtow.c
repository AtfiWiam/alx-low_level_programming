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
	int word_count = count_words(str), word_index = 0, word_length = 0, is_word = 0, i, j;
	char **words = (char **)malloc((word_count + 1) * sizeof(char *));

	if (str == NULL || *str == '\0' || word_count == 0 || words == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] != ' ')
		{
			if (!is_word)
				is_word = 1, word_length = 0;
			word_length++;
		}
		else if (is_word)
		{
			words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
			if (words[word_index] == NULL)
			{
				for (j = 0; j < word_index; ++j)
				{
					free(words[j]);
				}
				free(words);
				return (NULL);
			}
		strncpy(words[word_index], str + i - word_length, word_length);
		words[word_index][word_length] = '\0';
		word_index++, is_word = 0;
		}
	}
	if (is_word)
	{
		words[word_index] = (char *)malloc((word_length + 1) * sizeof(char));
		if (words[word_index] == NULL)
		{
			for (j = 0; j < word_index; ++j)
				free(words[j]);
			free(words);
			return (NULL);
		}
		strncpy(words[word_index], str + strlen(str) - word_length, word_length);
		words[word_index][word_length] = '\0';
		word_index++;
	}
	words[word_index] = NULL;
	return (words);

}
