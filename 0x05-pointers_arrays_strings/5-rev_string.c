#include "main.h"


/**
 * _strlen - function to calculate the length of a string.
 * @s: string value.
 * Return: length
 */

int _strlen(char *s)
{
	 int length = 0;

	 while (*s != '\0')
	 {
		 length++;
		 s++;
	 }

	 return (length);
}


/**
 * swap - function swap two characters.
 * @s: string value.
 * Return: void.
 */

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * rev_string - function that reverses a string.
 * @s: string value.
 * Return: void.
 */

void rev_string(char *s)
{
	int length = _strlen(s);
	char *start = s;
	char *end = s + length - 1;

	while (start < end)
	{
		swap(start, end);
		start++;
		end--;
	}
}

