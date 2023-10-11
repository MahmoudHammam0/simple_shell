#include "main.h"

/**
 * printenv - prints the environment
 *
 * @cmd: string
 */
void printenv(char *cmd)
{
	int i = 0;

	while (cmd)
	{
		cmd =  environ[i++];
		write(1, cmd, _strlen(cmd));
		if (environ[i] != NULL)
			write(1, "\n", 1);
	}
	free(cmd);
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
		free(s);
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(s, "env") == 0)
	{
		printenv("env");
		free(s);
		return (0);
	}
	return (1);
}
