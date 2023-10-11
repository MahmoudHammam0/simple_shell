#include "main.h"

/**
 * printenv - prints the environment
 *
 * @cmd: string
 */
void printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		write(1, environ[i], _strlen(environ[i]));
		if (environ[i + 1] != NULL)
			write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
}

/**
 * execute_builtin - handles builtin commands
 *
 * @s: builtin commands
 *
 * Return: 0 if builtin, 1 if not
 */
int execute_builtin(char *s)
{
	if (_strcmp(s, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(s, "env") == 0)
	{
		printenv();
		return (0);
	}
	return (1);
}
