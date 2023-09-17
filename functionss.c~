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
/**
 * arg_count - counts the no. of arguments
 * @comm : command entered by user
 * Return: no of arguments
 */
int arg_count(const char *comm)
{
	int count = 0;
	int in_wrd = 0;
	int i;

	for (i = 0; comm[i] != '\0'; i++)
	{
		if (comm[i] == ' ')
		{
			if (in_wrd)
				in_wrd = 0;
		} else
		{
			if (!in_wrd)
			{
				count++;
				in_wrd = 1;
			}
		}
	}
	return (count);
}
/**
 * handle_argument - handle the array of arguments
 * @x: the input from the user
 * Return: pointer to array of pointers to the arguments
 */
char **handle_argument(char *x)
{
	int l = arg_count(x);
	char **p = malloc(sizeof(char *) * (l + 1));
	char *s;
	char *tok;
	int i = 0;

	if (p == NULL)
	{
		perror("malloc");
		exit(1);
	}
	s = strdup(x);
	tok = strtok(s, " ");
	while (tok != NULL)
	{
		p[i] = strdup(tok);
		if (p[i] == NULL)
		{
			perror("strdup");
			exit(1);
		}
		tok = strtok(NULL, " ");
		i++;
	}
	p[i] = NULL;
	free(s);
	return (p);
}
