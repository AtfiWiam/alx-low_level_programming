#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional
 * array of integers.
 *
 * @width: width of the array.
 * @height: height of the array.
 *
 * Return: pointer to an 2 dimensional array, or NULL if faillure.
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int a, b;

	if (width < 1 || height < 1)
	{
		return (NULL);
	}

	grid = malloc(height * sizeof(int *));
	if (grid == NULL)
	{
		free(grid);
		return (NULL);
	}

	for (a = 0; a < height; a++)
	{
		grid[a] = malloc(width * sizeof(int));
		if (grid[a] == NULL)
		{
			for (a--; a >= 0; a--)
				free(grid[a]);
			free(grid);
			return (NULL);
		}
	}

	for (a = 0; a < height; a++)
	{
		for (b = 0; b < width; b++)
		{
			grid[a][b] = 0;
		}
	}

	return (grid);
}
