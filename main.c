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

	(void)argc;
	while (1)
	{
		printf("($) ");
		r = getline(&command, &l, stdin);
		fflush(stdin);
		if (r != -1)
		{
			rm_newline(command);
			args = handle_argument(command);
			execute(args, env, argv);
		} else
		{
			perror(argv[0]);
		}
	}
	free(command);
	free(args);
	return (0);
}
