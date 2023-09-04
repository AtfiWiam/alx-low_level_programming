#include "main.h"

#define BUFFER_SIZE 1024

int copy_file(const char *source, const char *destination);
void handle_error(const char *message, int exit_code);

/**
* main - program that copies the content of a file to another file
* @argc: num argument
* @argv: string argument
* Return: 0
*/

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}
	if (copy_file(argv[1], argv[2]) == -1)
		return (99);
	return (0);
}

/**
 * copy_file - function to handle the file copying logic
 * @source : pointer to source file to be copied.
 * @destination : pointer to destination file.
 *
 * Return : (0) on success or (-1) failure
 */

int copy_file(const char *source, const char *destination)
{
	int fd_source, fd_destination;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	fd_source = open(source, O_RDONLY);
	if (fd_source == -1)
	{
		handle_error("Error: Can't read from file", 98);
		return (-1);
	}
	fd_destination = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_destination == -1)
	{
		handle_error("Error: Can't write to file", 99);
		close(fd_source);
		return (-1);
	}
	while ((bytes_read = read(fd_source, buffer, sizeof(buffer))) > 0)
	{
		bytes_written = write(fd_destination, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			handle_error("Error: Can't write to file", 99);
			close(fd_source);
			close(fd_destination);
			return (-1);
		}
	}
	if (bytes_read == -1)
	{
		handle_error("Error: Can't read from file", 98);
		close(fd_source);
		close(fd_destination);
		return (-1);
	}
	close(fd_source);
	close(fd_destination);
	return (0);
}

/**
 * handle_error - function to handle error messages and exit codes
 * @message : message to be printed
 * @exit_code : exit code
 * return : nothing
 */

void handle_error(const char *message, int exit_code)
{
	dprintf(2, "%s\n", message);
	exit(exit_code);
}
