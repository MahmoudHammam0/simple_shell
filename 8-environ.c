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

/**
 * _unsetenv - deletes the variable from the environment
 * @cmd: array of arguments strings
 * @env: change in environ
 * Return: 0 (Success) -1 on failure
 */
int _unsetenv(char **cmd, int *env)
{
	int i;
	char *name, *tok, *str;

	if (cmd[1] == NULL)
		return (-1);
	for (i = 0; environ[i] != NULL; i++)
	{
		name = _strcpy(environ[i]);
		tok = strtok(name, "=");
		if (_strcmp(tok, cmd[1]) == 0)
		{
			str = environ[i];
			for ( ; environ[i] != NULL; i++)
				environ[i] = environ[i + 1];
			environ[i] = NULL;
			free(name), name = NULL;
			if (*env > 0)
				free(str), str = NULL;
			return (0);
		}
		free(name), name = NULL;
		tok = NULL;
	}
	return (0);
}
