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

	while (x[i] != '\n' && x[i] != '\0')
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
	char **p = malloc(sizeof(char *) * (l + 3));
	char *s;
	char *tok;
	int i = 0;

	if (p == NULL)
	{
		perror("malloc");
		exit(1);
	}
	s = _strdup(x);
	tok = strtok(s, " ");
	while (tok != NULL)
	{
		p[i] = _strdup(tok);
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
/**
 * execute - searches and executes command
 * @args: arguments of command
 * @env: enviroment
 * @argv: array of arguments vector
 */
void execute(char **args, char **env, char *argv[])
{
	int i;
	char *pathptr = NULL;
	char **patharr = NULL;
	int n = _strcmp(args[0], "env");
	int l = _strcmp(args[0], "exit");
	char *comm = NULL;
	int flag = 0;

	if (args[0][0] == '/')
	{
		if (access(args[0], X_OK) == 0)
		{
			_execute(args, env, args[0], argv[0]);
			flag = 1;
		}
	} else if (n == 1 || l == 1)
		check_exit(args);
	else if (n == 0)
	{
		for (i = 0; env[i] != NULL; i++)
			if (_strncmp(env[i], "PATH=", 5) == 1)
				pathptr = env[i] + 5;
		patharr = get_path(pathptr);
		for (i = 0; patharr[i] != NULL; i++)
		{
			sstrcat(patharr[i], "/");
			sstrcat(patharr[i], args[0]);
			comm = patharr[i];
			if (access(comm, X_OK) == 0)
			{
				_execute(args, env, comm, argv[0]);
				flag = 1;
				break;
			}
		}
		clean_a(patharr);
	}
	if (n != 1 && !flag)
		perror(argv[0]);
}

