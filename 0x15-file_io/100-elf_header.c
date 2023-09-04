#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_elf_header_info - Print information from an ELF header.
 * @header: Pointer to the ELF header structure.
 *
 * This function prints various information contained in the ELF header,
 * such as magic bytes, class, data format, version, OS/ABI, ABI version,
 * type, and entry point address.
 *
 * Return : Nothing.
 */

void print_elf_header_info(Elf64_Ehdr *header)
{
	int i;

	printf("Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", header->e_ident[i]);
		if (i < EI_NIDENT - 1)
			printf(" ");
	}
	printf("\n");
	printf("Class:                             %s\n", header->e_ident[EI_CLASS]
			== ELFCLASS32 ? "ELF32" : (header->e_ident[EI_CLASS]
				== ELFCLASS64 ? "ELF64" : "Unknown"));
	printf("Data:                              %s\n", header->e_ident[EI_DATA]
			== ELFDATA2LSB ?
			"2's complement, little endian" : (header->e_ident[EI_DATA]
				== ELFDATA2MSB ?
				"2's complement, big endian" : "Unknown"));
	printf("Version:                           %d (current)\n",
			header->e_ident[EI_VERSION]);
	printf("OS/ABI:                            %d\n", header->e_ident[EI_OSABI]);
	printf("ABI Version:                       %d\n",
			header->e_ident[EI_ABIVERSION]);
	printf("Type:                              %s\n", header->e_type == ET_REL ?
			"REL (Relocatable file)" : (header->e_type == ET_EXEC ?
				"EXEC (Executable file)" : (header->e_type == ET_DYN ?
					"DYN (Shared object file)" : "Unknown")));
	printf("Entry point address:               0x%lx\n",
			(unsigned long)header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: Number of command line arguments.
 * @argv: Array of command line arguments.
 *
 * This function is the main entry point of the program. It opens an ELF file,
 * reads its header, and then prints information from the ELF header using the
 * print_elf_header_info function.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cannot open file '%s'\n", argv[1]);
		return (98);
	}
	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Cannot read ELF header from file '%s'\n",
				argv[1]);
		close(fd);
		return (98);
	}
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: '%s' is not an ELF file\n", argv[1]);
		close(fd);
		return (98);
	}

	print_elf_header_info(&header);
	close(fd);
	return (0);

}
