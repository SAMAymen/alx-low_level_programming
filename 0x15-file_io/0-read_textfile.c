#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: path to file to be read
 * @letters: chars to read and print
 * Return: chars read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buff = NULL;
	ssize_t bytes = 0;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buff = malloc(sizeof(char) * letters);
	if (!buff)
	{
		close(fd);
		return (0);
	}

	bytes = read(fd, buff, letters);

	if (bytes == -1 || write(STDOUT_FILENO, buff, bytes) == -1)
		bytes = (0);

	close(fd);
	free(buff);
	return (bytes);
}

