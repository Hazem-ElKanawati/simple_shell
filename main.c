#include "main.h"

/**
 * main - runs the shell
 * @argc: arg count
 * @argv: arg vector
 * @env: enviroment array
 * Return: 0(Success) 1(Error)
 */
int main(int argc, char *argv[], char **env)
{
	ssize_t r;
	size_t l = 0;
	char *command = NULL;
	char **args;
	pid_t p;

	(void)argc;
	while (1)
	{
		printf("($) ");
		r = getline(&command, &l, stdin);
		rm_newline(command);
		args = handle_argument(command);
		if (r != -1 && access(args[0], X_OK) == 0)
		{
			p = fork();
			if (p == -1)
			{
				perror(argv[0]);
			} else if (p == 0)
			{
				execve(args[0], args, env);
				perror(argv[0]);
				_exit(EXIT_FAILURE);
			} else
			{
				wait(NULL);
			}
		} else
		{
			perror(argv[0]);
		}
	}
	free(command);
	return (0);
}
