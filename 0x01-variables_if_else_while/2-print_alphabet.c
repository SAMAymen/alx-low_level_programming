#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: 'this program prints alphabets a to z'
 *
 * Return: 0 Always (Success)
 */
int main(void)
{
	char alphabet = 'a';
		while (alphabet <= 'z')
		{
			putchar(alphabet);
			alphabet++;
		}
	putchar('\n');
	return (0);
}
