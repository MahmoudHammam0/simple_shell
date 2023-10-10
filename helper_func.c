#include "main.h"
/**
 * _getenv - gets value of enviroment variable
 * @s: name of variable
 * Return: value of variable
 */
char *_getenv(char *s)
{
	int i;
	char *cp, *tok, *value, *del = "=";

	if (s == NULL)
		return (NULL);
	for (i = 0; environ[i] != NULL; i++)
	{
		cp = _strcpy(environ[i]);
		tok = strtok(cp, del);
		if (_strcmp(tok, s) == 0)
			break;
		free(cp), cp = NULL;
		tok = NULL;
	}
	tok = strtok(NULL, del);
	value = _strcpy(tok);
	free(cp), cp = NULL;
	return (value);
}
