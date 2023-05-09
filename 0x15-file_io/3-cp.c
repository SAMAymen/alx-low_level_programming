#include "main.h"

#define READ_ERR "Error: Can't read from file %s\n"
#define WRITE_ERR "Error: Can't write to %s\n"

int open_file(const char *path, int flags, int mode);
int copy_file(int from, int to);

/**
 * cp - Copy the content of a file to another file.
 * @argc: Number of arguments.
 * @argv: Arguments vector.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int from, to, ret;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (EXIT_FAILURE);
	}

	from = open_file(argv[1], O_RDONLY, 0);
	if (from == -1)
	{
		dprintf(STDERR_FILENO, READ_ERR, argv[1]);
		return (EXIT_FAILURE);
	}

	to = open_file(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (to == -1)
	{
		close(from);
		dprintf(STDERR_FILENO, WRITE_ERR, argv[2]);
		return (EXIT_FAILURE);
	}

	ret = copy_file(from, to);

	if (close(from) == -1 || close(to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file descriptor\n");
		return (EXIT_FAILURE);
	}

	return (ret);
}

/**
 * open_file - Opens a file.
 * @path: The path to the file.
 * @flags: The flags to use when opening the file.
 * @mode: The mode to use when creating a new file.
 *
 * Return: The file descriptor, or -1 on failure.
 */
int open_file(const char *path, int flags, int mode)
{
	int fd = open(path, flags, mode);

	if (fd == -1)
		return (-1);
	return (fd);
}

/**
 * copy_file - Copies the contents of one file to another.
 * @from:  The file descriptor of the source file.
 * @to: The file descriptor of the destination file.
 *
 * Return: 0 on success, or -1 on failure.
 */
int copy_file(int from, int to)
{
	char buffer[BUFSIZ];
	ssize_t nread, nwritten;

	while ((nread = read(from, buffer, BUFSIZ)) > 0)
	{
		nwritten = write(to, buffer, nread);
		if (nwritten == -1 || nwritten != nread)
			return (-1);
	}

	if (nread == -1)
		return (-1);

	return (0);
}
