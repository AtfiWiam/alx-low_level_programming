#include "main.h"
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of
 * a program.
 * @ac: total arguments.
 * @av: command line arguments.
 *
 * Return: pointer to a new string, or NULL if faillure.
 */
char *argstostr(int ac, char **av)
{
	char *concates;
	int i, j, length, k;

	if (ac == 0)
		return (NULL);

	for (length = i = 0; i < ac; i++)
	{
		if (av[i] == NULL)
			return (NULL);

		for (j = 0; av[i][j] != '\0'; j++)
			length++;

		length++;
	}

	concates = malloc((length + 1) * sizeof(char));
	if (concates == NULL)
	{
		free(concates);
		return (NULL);
	}

	for (i = j = k = 0; k < length; j++, k++)
	{
		if (av[i][j] == '\0')
		{
			concates[k] = '\n';
			i++;
			k++;
			j = 0;
		}
		if (k < length - 1)
			concates[k] = av[i][j];
	}
	concates[k] = '\0';

	return (concates);
}
