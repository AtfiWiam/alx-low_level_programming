#include "main.h"

/**
 * _atoi - function that convert a string to an integer.
 * @s: string value.
 * Return: integer value.
 */
int _atoi(char *s)
{
	unsigned int lenght = 0, size = 0, a = 0, b = 1, c = 1;
	unsigned int i;

	while (*(s + lenght) != '\0')
	{
		if (size > 0 && (*(s + lenght) < '0' || *(s + lenght) > '9'))
		{
			break;
		}
		if (*(s + lenght) == '-')
		{
			b *= -1;
		}
		if ((*(s + lenght) >= '0') && (*(s + lenght) <= '9'))
		{
			if (size > 0)
			{
				c *= 10;
			}
			size++;
		}
		lenght++;
	}

	for (i = lenght - size; i < lenght; i++)
	{
		a = a + ((*(s + i) - 48) * c);
		c /= 10;
	}
	return (a * b);
}

