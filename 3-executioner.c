#include "main.h"
/**
 * executioner - execute commands
 * @cmd: array of strings(command arguments)
 * @argv: array of strings (commandline arguments)
 * @g: command number
 * Return: exit status
 */
int executioner(char **cmd, char **argv, int g)
{
	pid_t pid;
	int stat = 0, v, p, c;
	char *str = NULL;

	p = path_check(cmd[0]);
	if (p == 0)
	{
		str = get_path(cmd[0]);
		if (str == NULL)
		{
			_error(cmd[0], argv, g);
			_free(cmd);
			return (127);
		}
		free(cmd[0]), cmd[0] = NULL;
		cmd[0] = str;
	}
	c = cmd_check(cmd[0]);
	if (p == 1 && c == -1)
		_error(cmd[0], argv, g);
	if (c == 1)
	{
		pid = fork();
		if (pid == 0)
		{
			v = execve(cmd[0], cmd, environ);
			if (v < 0)
			{
				_error(cmd[0], argv, g);
				_free(cmd);
				exit(126);
			}
		}
		else
			waitpid(pid, &stat, 0);
	}
	_free(cmd);
	return (WEXITSTATUS(stat));
}
/**
 * path_check - check for full path of command
 * @s: path of command
 * Return: 1 if command passed by it path 0 if command name only
 */
int path_check(char *s)
{
	int i;

	if (s == NULL)
		return (0);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '/')
			return (1);
	}
	return (0);
}
/**
 * get_path - search PATH for command
 * @str: command name
 * Return: full path to command
 */
char *get_path(char *str)
{
	char *tok = NULL, *cp = NULL, *d = ":", *value = NULL;
	struct stat p;

	if (str == NULL)
		return (NULL);
	value = _getenv("PATH");
	if (value == NULL)
		return (NULL);
	tok = strtok(value, d);
	while (tok)
	{
		cp = malloc(_strlen(tok) + _strlen(str) + 2);
		if (cp == NULL)
		{
			free(value), value = NULL;
			return (NULL);
		}
		_stcpy(cp, tok);
		_strcat(cp, "/");
		_strcat(cp, str);
		if (stat(cp, &p) == 0)
		{
			free(value), value = NULL;
			return (cp);
		}
		tok = strtok(NULL, d);
		free(cp), cp = NULL;
	}
	free(value), value = NULL;
	return (NULL);
}
/**
 * _free - free array of strings
 * @cmd: array of strings to be freed
 * Return: Nothing
 */
void _free(char **cmd)
{
	int i;

	for (i = 0; cmd[i]; i++)
	{
		free(cmd[i]);
		cmd[i] = NULL;
	}
	free(cmd);
}
/**
 * cmd_check - check if the command exists
 * @s: full path to command
 * Return: 1 if the command exist
 */
int cmd_check(char *s)
{
	struct stat p;

	if (stat(s, &p) == 0)
		return (1);
	return (-1);
}
