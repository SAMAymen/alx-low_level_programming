#include "main.h"
#include <errno.h>

#define BUFFER_SIZE 1024
#define FILE_PERMS 0664
#define READ_ERR "Error: Can't read from file %s\n"
#define WRITE_ERR "Error: Can't write to %s\n"

/**
 * main - check the code for Holberton School students.
 * @argc: num of args
 * @argv: args
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int from, to, w, r, on_close;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMS);
	if (to == -1)
	{
		dprintf(STDERR_FILENO, WRITE_ERR, argv[2]);
		exit(99);
	}

	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{
		dprintf(STDERR_FILENO, READ_ERR, argv[1]);
		exit(98);
	}

	while ((r = read(from, buffer, BUFFER_SIZE)) > 0)
	{
		w = write(to, buffer, r);
		if (w == -1)
		{
			dprintf(STDERR_FILENO, WRITE_ERR, argv[2]);
			exit(99);
		}
	}

	if (r == -1)
	{
		dprintf(STDERR_FILENO, READ_ERR, argv[1]);
		exit(98);
	}

	on_close = close(from);
	if (on_close == -1)
	{
		perror("Error");
		exit(100);
	}

	on_close = close(to);
	if (on_close == -1)
	{
		perror("Error");
		exit(100);
	}

	return (0);
}