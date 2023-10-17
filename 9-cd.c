#include "main.h"
/**
 * _cd - change current directory
 * @cmd: array of arguments strings
 * @env: environ change
 * Return: 0 Success -1 failure
 */
int _cd(char **cmd, int *env)
{
	int x;
	char *curr_path = NULL, *new_path = NULL, *str = NULL;

	if (cmd[1] == NULL)
	{
		curr_path = getcwd(curr_path, 0);
		new_path = _getenv("HOME");
		chdir(new_path);
		env_update(new_path, curr_path, env);
		return (0);
	}
	if (_strcmp(cmd[1], "-") == 0)
	{
		curr_path = getcwd(curr_path, 0);
		new_path = _getenv("OLDPWD");
		chdir(new_path);
		str = getcwd(str, 0);
		write(1, str, _strlen(str));
		write(1, "\n", 1);
		env_update(new_path, curr_path, env);
		free(str), str = NULL;
		return (0);
	}
	curr_path = getcwd(curr_path, 0);
	new_path = path(curr_path, cmd[1]);
	x = chdir(new_path);
	if (x == -1)
	{
		free(curr_path), curr_path = NULL;
		free(new_path), new_path = NULL;
		return (-1);
	}
	free(new_path), new_path = NULL;
	new_path = getcwd(new_path, 0);
	env_update(new_path, curr_path, env);
	return (0);
}
/**
 * env_pwd - change pwd variable acc to current directory
 * @new: new pwd
 * @env: environ change
 * Return: new pwd
 */
char *env_pwd(char *new, int *env)
{
	char *pwd, *name, *tok;
	int i;

	pwd = malloc(_strlen(new) + _strlen("PWD") + 2);
	if (pwd == NULL)
	{
		free(new), new = NULL;
		return (NULL);
	}
	_stcpy(pwd, "PWD=");
	_strcat(pwd, new);
	for (i = 0; environ[i] != NULL; i++)
	{
		name = _strcpy(environ[i]);
		tok = strtok(name, "=");
		if (_strcmp(tok, "PWD") == 0)
		{
			if (*env > 0)
				free(environ[i]), environ[i] = NULL;
			environ[i] = pwd;
			free(name), name = NULL;
			free(new), new = NULL;
			return (pwd);
		}
		free(name), name = NULL;
		tok = NULL;
	}
	free(new), new = NULL;
	return (NULL);
}
/**
 * env_owd - change oldpwd acc to previous directory
 * @old: old variable value
 * @env: environ change
 * Return: oldpwd
 */
char *env_owd(char *old, int *env)
{
	char *owd, *name, *tok;
	int i;

	owd = malloc(_strlen(old) + _strlen("OLDPWD") + 2);
	if (owd == NULL)
	{
		free(old), old = NULL;
		return (NULL);
	}
	_stcpy(owd, "OLDPWD=");
	_strcat(owd, old);
	for (i = 0; environ[i] != NULL; i++)
	{
		name = _strcpy(environ[i]);
		tok = strtok(name, "=");
		if (_strcmp(tok, "OLDPWD") == 0)
		{
			if (*env > 0)
				free(environ[i]), environ[i] = NULL;
			environ[i] = owd;
			free(name), name = NULL;
			free(old), old = NULL;
			return (owd);
		}
		free(name), name = NULL;
		tok = NULL;
	}
	free(old), old = NULL;
	return (NULL);
}
/**
 * path - form path for cd
 * @curr_path: current path
 * @dir: directory name
 * Return: path to dir
 */
char *path(char *curr_path, char *dir)
{
	char *str;
	int n;

	str = malloc(_strlen(curr_path) + _strlen(dir) + 2);
	if (str == NULL)
	{
		free(curr_path), curr_path = NULL;
		return (NULL);
	}
	n = path_check(dir);
	if (n == 0)
	{
		_stcpy(str, curr_path);
		_strcat(str, "/");
		_strcat(str, dir);
		return (str);
	}
	else
		_stcpy(str, dir);
	return (str);
}
/**
 * cd_error - handle cd errors
 * @cmd: array of arguments strings
 * @argv: array of command line arguments
 * @g: number of commands executed
 * Return: Nothing
 */
void cd_error(char **cmd, char **argv, int g)
{
	char *str = NULL;

	print(argv[0]);
	print(": ");
	str = num_to_char(g);
	print(str);
	free(str);
	print(": cd: can't cd to ");
	print(cmd[1]);
	print("\n");
}
