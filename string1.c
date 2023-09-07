#include "main.h"

/**
 * sstrcat - concatenates two strings
 * @x: main string
 * @y: 2nd string to be added
 */

void sstrcat(char *x, char *y)
{
	int l1 = 0, i = 0;

	while (x[l1] != '\0')
		l1++;
	while (y[i] != '\0')
	{
		x[l1] = y[i];
		i++;
		l1++;
	}
	x[l1] = '\0';
}
/**
 * prstr - prints a simple string
 * @x: the string to be printed
 */

void prstr(char *x)
{
	int i = 0;

	while (x[i] != '\0')
	{
		prchar(x[i]);
		i++;
	}
}
