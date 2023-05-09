#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check_elf(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - Determines if the specified file is an ELF file.
 *
 * @e_ident: A pointer to an array representing the ELF magic numbers.
 *
 * If the file is not an ELF file, the function exits with error code 98.
 */
void check_elf(unsigned char *e_ident)
{
	if (strncmp((char *)e_ident, ELFMAG, SELFMAG) != 0)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 *
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: The magic numbers in hexadecimal format, separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x%s", e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
}

/**
 * print_class - Prints the class of an ELF header.
 *
 * @e_ident: A pointer to an array of bytes containing the ELF class.
 *
 * Description: Prints the ELF class as a string ("none", "ELF32", or "ELF64").
 */
void print_class(unsigned char *e_ident)
{
	const char *class_str = "<unknown>";

	if (e_ident[EI_CLASS] == ELFCLASSNONE)
		class_str = "none";
	else if (e_ident[EI_CLASS] == ELFCLASS32)
		class_str = "ELF32";
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		class_str = "ELF64";
	printf("  Class:                             %s\n", class_str);
}

/**
 * print_data - Prints the data encoding of an ELF header.
 *
 * @e_ident: A pointer to an array containing the ELF data encoding.
 *
 * Description: Prints the ELF data encoding as a string.
 */
void print_data(unsigned char *e_ident)
{
	const char *data_str = "<unknown>";

	if (e_ident[EI_DATA] == ELFDATANONE)
		data_str = "none";
	else if (e_ident[EI_DATA] == ELFDATA2LSB)
		data_str = "2's complement, little endian";
	else if (e_ident[EI_DATA] == ELFDATA2MSB)
		data_str = "2's complement, big endian";
	printf("  Data:                              %s\n", data_str);
}

/**
 * print_version - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 * Description: Prints the ELF version number.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	const char *osabi_str;

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			osabi_str = "UNIX - System V";
			break;
		case ELFOSABI_HPUX:
			osabi_str = "UNIX - HP-UX";
			break;
		case ELFOSABI_NETBSD:
			osabi_str = "UNIX - NetBSD";
			break;
		case ELFOSABI_LINUX:
			osabi_str = "UNIX - Linux";
			break;
		case ELFOSABI_SOLARIS:
			osabi_str = "UNIX - Solaris";
			break;
		case ELFOSABI_IRIX:
			osabi_str = "UNIX - IRIX";
			break;
		case ELFOSABI_FREEBSD:
			osabi_str = "UNIX - FreeBSD";
			break;
		case ELFOSABI_TRU64:
			osabi_str = "UNIX - TRU64";
			break;
		case ELFOSABI_ARM:
			osabi_str = "ARM";
			break;
		case ELFOSABI_STANDALONE:
			osabi_str = "Standalone App";
			break;
		default:
			osabi_str = "<unknown>";
			break;
	}
	printf("  OS/ABI:                            %s\n", osabi_str);
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
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
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 * Description: Prints the entry point address in hexadecimal format
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
		((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("  Entry point address:               %#x\n", (unsigned int)e_entry);
	} else
	{
		printf("  Entry point address:               %#lx\n", e_entry);
	}
}

/**
 * close_elf - Closes an ELF file descriptor to close.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed : exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the ELF header.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Description: If the file is not an ELF file or the function fails.
 * Return: 0 on success.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));

	if (header == NULL)
	{
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: Can't allocate memory for ELF header\n");
		exit(98);
	}

	if (read(fd, header, sizeof(Elf64_Ehdr)) == -1)
	{
		free(header);
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: Can't read ELF header %s\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(fd);
	return (0);
}
