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
 * @s: builtin commands
 * @argv: array of command line arguments
 * @stat: pointer to exit status
 * @env: environ change
 * @g: number of command
 * Return: 0 if builtin, 1 if not
 */
int execute_builtin(char **s, char **argv, int *stat, int *env, int g)
{
	char *str;

	if (s[0] == NULL)
	{
		_free(s);
		return (0);
	}
	if (_strcmp(s[0], "exit") == 0)
	{
		exit_func(s, argv, stat, env, g);
		return (0);
	}
	if (_strcmp(s[0], "env") == 0)
	{
		printenv();
		*stat = 0;
		_free(s);
		return (0);
	}
	if (_strcmp(s[0], "setenv") == 0)
	{
		str = _setenv(s, env);
		if (str == NULL)
		{
			print("Error: invalid arguments\n");
			free(str), str = NULL;
			_free(s);
			return (-1);
		}
		new_env(str, env);
		*env = 1;
		_free(s);
		return (0);
	}
	return (1);
}
/**
 * exit_func - handles exit argument
 * @cmd: array of input strings
 * @argv: array of command line arguments
 * @stat: pointer to exit status
 * @env: environ change
 * @g: number of command
 * Return: Nothing
 */
void exit_func(char **cmd, char **argv, int *stat, int *env, int g)
{
	int val;
	char *str;

	if (cmd[1] != NULL)
	{
		if (_atoi(cmd[1]) > 0)
			*stat = _atoi(cmd[1]);
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
			*stat = 2;
			return;
		}
	}
	val = *stat;
	_free(cmd);
	if (*env > 0)
		_free(environ);
	exit(val);
}
/**
 * _setenv - add / change environ variable
 * @cmd: command arguments
 * @env: environ change
 * Return: add / changed variable
 */
char *_setenv(char **cmd, int *env)
{
	char *str;
	char *tok, *name;
	int i;

	if (cmd[1] == NULL || cmd[2] == NULL)
		return (NULL);
	str = malloc(_strlen(cmd[1]) + _strlen(cmd[2]) + 2);
	if (env == NULL)
		return (NULL);
	_stcpy(str, cmd[1]);
	_strcat(str, "=");
	_strcat(str, cmd[2]);
	for (i = 0; environ[i] != NULL; i++)
	{
		name = _strcpy(environ[i]);
		tok = strtok(name, "=");
		if (_strcmp(tok, cmd[1]) == 0)
		{
			free(name), name = NULL;
			if (*env > 0)
				free(environ[i]), environ[i] = NULL;
			environ[i] = str;
			return (str);
		}
		free(name), name = NULL;
		tok = NULL;
	}
	if (*env > 0)
		free(environ[i]), environ[i] = NULL;
	environ[i] = str;
	environ[i + 1] = NULL;
	return (str);
}
/**
 * new_env - make new array of environ strings
 * @str: newly added / changed variable
 * @env: environ change
 * Return: Nothing
 */
void new_env(char *str, int *env)
{
	int i;
	char **s;

	for (i = 0; environ[i] != NULL; i++)
		;
	s = malloc(sizeof(char *) * (i + 2));
	if (s == NULL)
		return;
	for (i = 0; environ[i] != NULL; i++)
		s[i] = _strcpy(environ[i]);
	s[i] = NULL;
	if (*env > 0)
	{
		_free(environ);
		*env = 0;
	}
	else
		free(str), str = NULL;
	environ = s;
}
