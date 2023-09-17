#include "main.h"

/**
 * _execute - executes command
 * @args: arguments of the command
 * @env: enviroment
 * @comm: command to execute
 * @name: name of the program
 */

void _execute(char **args, char **env, char *comm, char *name)
{
	pid_t p;

	p = fork();
	if (p == -1)
	{
		perror(name);
	} else if (p == 0)
	{
		execve(comm, args, env);
		perror(name);
	} else
	{
		wait(NULL);
	}
}
/**
 * get_path - handles the path
 * @pathptr: pointer to the path
 * Return: array of strings for each path
 */
char **get_path(char *pathptr)
{
	char *tok;
	int i;
	int n;
	char **p;

	p = malloc(sizeof(char *) * 25);
	if (p == NULL)
		return (NULL);
	tok = strtok(pathptr, ":");
	for (i = 0; tok != NULL; i++)
	{
		n = _strlen(tok);
		p[i] = malloc(sizeof(char) * (n + 2));
		if (p[i] == NULL)
			return (NULL);
		p[i] = _strdup(tok);
		sstrcat(p[i], "/");
		tok = strtok(NULL, ":");
	}
	return (p);
}

