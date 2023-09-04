#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_elf_info(char *magic);
void print_elf_type(char *magic);
void print_elf_osabi(char *magic);
void print_elf_version(char *magic);
void print_elf_data(char *magic);
void print_elf_magic(char *magic);
void check_elf_type(char *magic);
int is_elf_file(char *magic);

/**
 * print_elf_info - Prints the ELF header information.
 * @magic: magic pointer.
 *
 * Return: nothing.
 */

void print_elf_info(char *magic)
{
	int i;

	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", magic[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");
}

/**
 * print_elf_type - prints the ELF file type.
 * @magic: magic pointer.
 *
 * Return: nothing.
 */

void print_elf_type(char *magic)
{
	Elf32_Ehdr *header = (Elf32_Ehdr *)magic;

	printf("  Type:                              ");
	switch (header->e_type)
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", header->e_type);
			break;
	}
}

/**
 * print_elf_osabi - prints the ELF OS/ABI and ABI version.
 * @magic: magic pointer.
 *
 * Return: nothing.
 */

void print_elf_osabi(char *magic)
{
	char osabi = magic[EI_OSABI];

	printf("OS/ABI:  ");
	switch (osabi)
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		default:
			printf("<unknown: %x>\n", osabi);
			break;
	}
	printf("ABI Version: %d\n", magic[EI_ABIVERSION]);
}

/**
 * print_elf_version - prints the ELF version.
 * @magic: magic pointer.
 *
 * Return: nothing.
 */

void print_elf_version(char *magic)
{
	int version = magic[EI_VERSION];

	printf("Version: ");
	if (version == EV_CURRENT)
		printf("%d (current)\n", version);
	else
		printf("%d\n", version);
}

/**
 * print_elf_data - prints the ELF data format.
 * @magic: magic pointer.
 *
 * Return: nothing.
 */

void print_elf_data(char *magic)
{
	char data = magic[EI_DATA];

	printf("Data:    2's complement");
	if (data == ELFDATA2LSB)
		printf(", little endian\n");
	else if (data == ELFDATA2MSB)
		printf(", big endian\n");
}

/**
 * print_elf_magic - prints the ELF magic bytes.
 * @magic: magic pointer.
 *
 * Return: nothing.
 */

void print_elf_magic(char *magic)
{
	int bytes;

	printf("Magic:   ");
	for (bytes = 0; bytes < 16; bytes++)
	{
		printf(" %02x", magic[bytes]);
	}
	printf("\n");
}

/**
 * check_elf_type - checks the ELF file type.
 * @magic: magic pointer.
 *
 * Return: nothing.
 */

void check_elf_type(char *magic)
{
	char syst = magic[EI_CLASS] + '0';

	if (syst == '0')
		exit(98);
	printf("ELF Header:\n");
	print_elf_magic(magic);
	if (syst == '1')
		printf("  Class:                             ELF32\n");
	if (syst == '2')
		printf("  Class:                             ELF64\n");
	print_elf_data(magic);
	print_elf_version(magic);
	print_elf_osabi(magic);
	print_elf_type(magic);
}

/**
 * is_elf_file - checks if it is an ELF file.
 * @magic: magic pointer.
 *
 * Return: 1 if it is an ELF file, 0 if not.
 */

int is_elf_file(char *magic)
{
	char E = magic[EI_MAG1], L = magic[EI_MAG2], F = magic[EI_MAG3];
	int address = (int)magic[EI_MAG0];

	if (address == ELFMAG0 && E == ELFMAG1 && L == ELFMAG2 && F == ELFMAG3)
		return (1);
	return (0);
}

/**
 * main - Entry point for the ELF header program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 on success, or an error code if there's an issue.
 */

int main(int argc, char *argv[])
{
	char magic[27];
	int fd, ret_read;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}
	lseek(fd, 0, SEEK_SET);
	ret_read = read(fd, magic, 27);
	if (ret_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (!is_elf_file(magic))
	{
		dprintf(STDERR_FILENO, "Error: %s is not an ELF file\n", argv[1]);
		exit(98);
	}
	check_elf_type(magic);
	close(fd);
	return (0);
}
