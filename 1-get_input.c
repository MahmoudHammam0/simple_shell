#include "main.h"
/**
 * get_input - get the user input
 * Return: input string
 */
char *get_input(void)
{
	ssize_t a;
	size_t n = 0;
	char *buff = NULL;

	if (isatty(0) != 0)
		write(1, "cisfun$ ", 8);
	a = getline(&buff, &n, stdin);
	if (a == -1)
	{
		free(buff), buff = NULL;
		return (NULL);
	}
	return (buff);
}
