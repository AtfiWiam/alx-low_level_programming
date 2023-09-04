#include "main.h"

#define BUFFER_SIZE 1024

/**
* main - program that copies the content of a file to another file
* @argc: num argument
* @argv: string argument
* Return: 0
*/

int main(int argc, char *argv[])
{
	int source_fd, destination_fd;
	int bytes_read = 1024, bytes_written = 0;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	source_fd = open(argv[1], O_RDONLY);
	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	destination_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (destination_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(source_fd), exit(99);
	}
	while (bytes_read == 1024)
	{
		bytes_read = read(source_fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		bytes_written = write(destination_fd, buffer, bytes_read);
		if (bytes_written < bytes_read)
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
	}
	if (close(source_fd) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_fd);
	if (close(destination_fd) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", destination_fd);
	return (0);
}
