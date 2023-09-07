#include "main.h"

/**
 * prchar - prints a char
 * @x: character to be printed
 */

void prchar(char x)
{
	write(1, &x, 1);
}
/**
 * rm_newline - removes the newline character from the input
 * @x: array of chars
 */
void rm_newline(char *x)
{
	int i = 0;

	while (x[i] != '\n')
		i++;
	x[i] = '\0';
}
