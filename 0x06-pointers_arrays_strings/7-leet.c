#include "main.h"

/**
 * leet - function that encodes a string into 1337.
 * @str: string.
 * Return: pointer to str
 */

char *leet(char *str)
{
	char *ptr = str;
	char leet_chars[] = "aAeEoOtTlL";
	char leet_nums[] = "4433007711";
	int i, j;

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; leet_chars[j] != '\0'; j++)
		{
			if (str[i] == leet_chars[j])
			{
				str[i] = leet_nums[j];
				break;
			}
		}
	}
	return (ptr);
}
