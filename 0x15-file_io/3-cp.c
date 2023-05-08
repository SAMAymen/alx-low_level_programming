#include "main.h"

#define READ_ERR "Error: Can't read from file %s\n"
#define WRITE_ERR "Error: Can't write to %s\n"

/**
 * cp- just Copie the content of a file to another file.
 * @argc: num of args
 * @argv: args
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int from, to, w, r;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to == -1)
	{
		dprintf(STDERR_FILENO, WRITE_ERR, argv[2]);
		return (99);
	}

	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{
		dprintf(STDERR_FILENO, READ_ERR, argv[1]);
		return (98);
	}
	while ((r = read(from, buffer, 1024)) > 0)
	{
		w = write(to, buffer, r);
		if (w == -1)
		{
			dprintf(STDERR_FILENO, WRITE_ERR, argv[2]);
			return (99);
		}
	}
	close(from);
	close(to);

	if (from == -1 || to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", from == -1 ? from : to);
		return (100);
	}
	return (0);
}
