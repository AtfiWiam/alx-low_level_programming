#include "main.h"

/**
 * _isupper - checks if the character is uppercase
 * @u: int that will use for the argument of the function
 * Return: 1 if uppercase character 0 if not
 */
int _isupper(int u)
{
	if (u >= 'A' && u <= 'Z')
		return (1);
	else
		return (0);
}
