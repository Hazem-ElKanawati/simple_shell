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
/**
 * check_exit - checks if the command is exit
 * @args: command and arguments
 * Return: 0(Command is Not Exit)
 */

int check_exit(char **args)
{

	if (_strcmp(args[0], "exit") == 1)
		exit(0);
	else
		return (0);

}
