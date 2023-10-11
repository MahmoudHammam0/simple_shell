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
int execute_builtin(char **s)
{
	if (s[0] == NULL)
	{
		_free(s);
		return (0);
	}
	if (_strcmp(s[0], "exit") == 0)
	{
		_free(s);
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(s[0], "env") == 0)
	{
		printenv();
		_free(s);
		return (0);
	}
	return (1);
}
