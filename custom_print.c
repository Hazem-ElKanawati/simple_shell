#include "main.c"

/**
 * custom_print - This is to print the a command
 * @text: The message to be inputed
 *
 * Return: (Successful)
 */

void custom_print(const char *text)
{
	write(STDOUT_FILNO, text, strlen(text));
}
