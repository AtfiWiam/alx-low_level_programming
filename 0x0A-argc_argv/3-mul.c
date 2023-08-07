#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two given numbers.
 * @argc: number of command line argumments.
 * @argv: arguments passed to the program.
 *
 * Return: 0 (Success), 1 if error.
 */

int main(int argc, char *argv[])
{
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	printf("%d\n", num1 * num2);
	return (0);
}
