#include "main.h"

#define BUFFER_SIZE 1024

/**
 * handle_errors - checks for file error.
 * @source_fd: source file.
 * @destination_fd: destination file.
 * @argv: command line arguments.
 * Return: void, no return.
 */

void handle_errors(int source_fd, int destination_fd, char *argv[])
{
	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (destination_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - entry point function.
 * @argc: command line arguments count.
 * @argv: command line arguments.
 * Return: Always 0, with error if there is.
 */

int main(int argc, char *argv[])
{
	int source_fd, destination_fd, close_result;
	ssize_t num_chars, num_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	source_fd = open(argv[1], O_RDONLY);
	destination_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	handle_errors(source_fd, destination_fd, argv);
	num_chars = BUFFER_SIZE;
	while (num_chars == BUFFER_SIZE)
	{
		num_chars = read(source_fd, buffer, BUFFER_SIZE);
		if (num_chars == -1)
			handle_errors(-1, 0, argv);
		num_written = write(destination_fd, buffer, num_chars);
		if (num_written == -1)
			handle_errors(0, -1, argv);
	}
	close_result = close(source_fd);
	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_fd);
		exit(100);
	}
	close_result = close(destination_fd);
	if (close_result == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", destination_fd);
		exit(100);
	}
	return (0);
}
