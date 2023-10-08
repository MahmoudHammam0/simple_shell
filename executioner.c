#include "main.h"

/**
 * add_path - adds the path /bin/ at the beginning
 * @str: input string
 *
 * Return: the updated string
 */
char *add_path(char *str)
{
	char *full_path;

	full_path = _strcpy("/bin/");
	strcat(full_path, str);

	free(str);
	str = strdup(full_path);
	if (str == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	return (str);
}


/**
 * executioner - execute commands
 * @cmd: array of strings(command arguments)
 * @argv: array of strings (commandline arguments)
 * @input: input string
 * Return: exit status
 */
int executioner(char **cmd, char **argv, char *input)
{
	pid_t pid;
	int stat, v, p;
	char *str;

	pid = fork();
	if (pid == 0)
	{
		p = path_check(cmd[0]);
		if (p == 0)
		{
			str = get_path(cmd[0]);
			if (str == NULL)
			{
				perror(argv[0]);
				exit(0);
			}
			cmd[0] = str;
		}
		v = execve(cmd[0], cmd, environ);
		if (v < 0)
		{
			perror(argv[0]);
			exit(0);
		}
	}
	else
	{
		waitpid(pid, &stat, 0);
	}
	free(input);
	free(cmd);
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
	int i;
	char *path = "PATH", *del = "=", *tok, *cp;
	char *d = ":", *value;
	struct stat p;

	for (i = 0; environ[i] != NULL; i++)
	{
		cp = _strcpy(environ[i]);
		tok = strtok(cp, del);
		if (_strcmp(tok, path) == 0)
			break;
		free(cp);
		tok = NULL;
	}
	tok = strtok(NULL, del);
	value = _strcpy(tok);
	free(cp);
	tok = strtok(value, d);
	while (tok)
	{
		cp = malloc(30);
		cp = _strcpy(tok);
		_strcat(cp, "/");
		_strcat(cp, str);
		if (stat(cp, &p) == 0)
			return (cp);
		tok = strtok(NULL, d);
		free(cp);
	}
	return (NULL);
}
