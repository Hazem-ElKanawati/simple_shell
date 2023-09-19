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
	int i;

	p = fork();

	if (p == -1)
	{
		perror(name);
	}
	else if (p == 0)
	{
		execve(comm, args, env);
		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
		exit(1);
		perror(name);
	}
	else
	{
		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
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
	char **p = (char **)malloc(sizeof(char *) * 25);
	char *temp = NULL;

	temp = _strdup(pathptr);

	if (p == NULL)
		return (NULL);

	tok = strtok(temp, ":");

	for (i = 0; tok != NULL; i++)
	{
		n = _strlen(tok);
		p[i] = malloc(sizeof(char) * (n + 2));

		if (p[i] == NULL)
			return (NULL);

		p[i] = _strdup(tok);
		tok = strtok(NULL, ":");
	}

	free(temp);

	return (p);
}

