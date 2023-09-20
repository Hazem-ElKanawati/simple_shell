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
/**
 * _strdup - duplicates a string
 * @x: the string
 * Return: pointer to the duplicated string
 */
char *_strdup(char *x)
{
	int i = 0, n = 0;
	char *p;

	while (x[n] != '\0')
		n++;
	p = (char *)malloc(sizeof(char) * (n + 4));
	if (p == NULL)
		return (NULL);
	for (i = 0; i < n; i++)
		p[i] = x[i];
	p[i] = '\0';
	return (p);
}
/**
 * _strcmp - compares 2 strings
 * @x: 1st string
 * @y: 2nd string
 * Return: 1 (Same string) 0 (Different Strings)
 */
int _strcmp(char *x, char *y)
{
	int i;

	for (i = 0; x[i] != '\0' && y[i] != '\0'; i++)
	{
		if (x[i] != y[i])
			return (0);
	}
	return (1);
}
/**
 * _strlen - counts lentgh of a string
 * @x: the string
 * Return: length of the string
 */
int _strlen(char *x)
{
	int i = 0;

	while (x[i] != '\0')
		i++;
	return (i);
}
