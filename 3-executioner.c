#include "main.h"
/**
 * executioner - execute commands
 * @cmd: array of strings(command arguments)
 * @argv: array of strings (commandline arguments)
 * Return: exit status
 */
int executioner(char **cmd, char **argv)
{
	pid_t pid;
	int stat, v, p, c;
	char *str = NULL;

	if (cmd == NULL)
		return (WEXITSTATUS(stat));
	p = path_check(cmd[0]);
	if (p == 0)
	{
		str = get_path(cmd[0]);
		if (str == NULL)
		{
			perror(argv[0]);
			_free(cmd);
			return (WEXITSTATUS(stat));
		}
		free(cmd[0]), cmd[0] = NULL;
		cmd[0] = str;
	}
	c = cmd_check(cmd[0]);
	if (p == 1 && c == -1)
		perror(argv[0]);
	if (c == 1)
	{
		pid = fork();
		if (pid == 0)
		{
			printf("fork has been called\n");
			v = execve(cmd[0], cmd, environ);
			if (v < 0)
			{
				perror(argv[0]);
				exit(0);
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
		return (-1);
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
	tok = strtok(value, d);
	while (tok)
	{
		cp = malloc(128);
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
