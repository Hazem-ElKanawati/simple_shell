#include "main.h"

/**
 * _strncmp - compares first n chars of a string with another string
 * @x: first string
 * @y: second string
 * @n: no. of chars
 * Return: 1 (if they are the same) 0 (different strings)
 */

int _strncmp(char *x, char *y, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (x[i] != y[i] || x[i] == '\0' || y[i] == '\0')
			return (0);
	}
	return (1);
}
