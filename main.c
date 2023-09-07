#include "main.h"

/**
 * main - runs the shell
 * @argc: arg count
 * @argv: arg vector
 * Return: 0(Success) 1(Error)
 */

int main(int argc, char *argv[])
{
	ssize_t r;
	size_t l = 0;
	char *command = NULL;
	char *const args[] = {"./hsh", NULL};
	pid_t p;

	if (argc == 2)
	{
		execve(argv[1], args, environ);
	}
	else if (argc == 1)
	{
		while (1)
		{
			prstr("($) ");
			r = getline(&command, &l, stdin);
			rm_newline(command);
			if (r != -1 && access(command, X_OK) == 0)
			{
				p = fork();
				if (p == -1)
					perror("./hsh");
				else if (p == 0)
				{
				execve(command, args, environ);
				}
				else
					wait(NULL);
			}
			else
				perror("./hsh");

		}
	}
	free(command);
	return (0);
}
