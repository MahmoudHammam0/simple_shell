#include "main.h"
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
		built_in0(s, env);
		return (0);
	}
	if (_strcmp(s[0], "unsetenv") == 0)
	{
		built_in1(s, env);
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
 * built_in0 - handle setenv command
 * @cmd: array of arguments strings
 * @env: change in environ
 * Return: Nothing
 */
void built_in0(char **cmd, int *env)
{
	char *str;

	str = _setenv(cmd, env);
	if (str == NULL)
	{
		print("Error: invalid arguments\n");
		free(str), str = NULL;
		_free(cmd);
		return;
	}
	new_env(str, env);
	*env = 1;
	_free(cmd);
}
/**
 * built_in1 - handle unsetenv command
 * @cmd: array of arguments strings
 * @env: change in environ
 * Return: Nothing
 */
void built_in1(char **cmd, int *env)
{
	char *str = NULL;
	int n;

	n = _unsetenv(cmd, env);
	if (n == -1)
	{
		print("Error: invalid arguments\n");
		_free(cmd);
		return;
	}
	new_env(str, env);
	*env = 1;
	_free(cmd);
}
