#include "main.h"

/**
 * printenv - prints the environment
 *
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
int execute_builtin(char **s, char **argv, int *stat, int g)
{
	if (s[0] == NULL)
	{
		_free(s);
		return (0);
	}
	if (_strcmp(s[0], "exit") == 0)
	{
		exit_func(s, argv, stat, g);
		return (0);
	}
	if (_strcmp(s[0], "env") == 0)
	{
		printenv();
		*stat = 0;
		_free(s);
		return (0);
	}
	return (1);
}
void exit_func(char **cmd, char **argv, int *stat, int g)
{
	int val = *stat;
	char *str;

	if (cmd[1] != NULL)
	{
		if (_atoi(cmd[1]) > 0)
			val = _atoi(cmd[1]);
		else
		{
			str = num_to_char(g);
			print(argv[0]);
			print(": ");
			print(str);
			free(str), str = NULL;
			print(": exit: Illegal number: ");
			print(cmd[1]);
			print("\n");
			_free(cmd);
			return;
		}
	}
	_free(cmd);
	exit(val);
}
