#include "main.h"
/**
 * _getenv - gets value of enviroment variable
 * @s: name of variable
 * Return: value of variable
 */
char *_getenv(char *s)
{
	int i;
	char *cp = NULL, *tok = NULL, *value = NULL, *del = "=";

	if (s == NULL)
		return (NULL);
	for (i = 0; environ[i] != NULL; i++)
	{
		cp = _strcpy(environ[i]);
		tok = strtok(cp, del);
		if (_strcmp(tok, s) == 0)
		{
			if (_stcmp(tok, s) == 0)
				break;
		}
		free(cp), cp = NULL;
		tok = NULL;
	}
	if (environ[i] == NULL)
		return (NULL);
	tok = strtok(NULL, del);
	value = _strcpy(tok);
	free(cp), cp = NULL;
	return (value);
}
/**
 * print - print string to stdout
 * @s: string to be printed
 * Return: Nothing
 */
void print(char *s)
{
	write(2, s, _strlen(s));
}
/**
 * _error - print errors to stdout
 * @s: command name
 * @argv: contain program name
 * @g: command number
 * Return: Nothing
 */
void _error(char *s, char **argv, int g)
{
	char *str = NULL;

	print(argv[0]);
	print(": ");
	str = num_to_char(g);
	print(str);
	free(str);
	print(": ");
	print(s);
	print(": not found\n");
}
/**
 * _getline - reads a line from stdin
 * @lineptr: pointer to string buffer
 * @n: memory allocated to buffer
 * @stream: stdin
 * Return: number of bytes read
 */
int _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buff;
	int r, i, fd = 0;

	(void)*stream;
	if (*lineptr == NULL)
	{
		buff = malloc(sizeof(char) * 1024);
		*n = 1024;
		if (buff == NULL)
			return (-1);
	}
	*buff = '\0';
	r = read(fd, buff, *n);
	*lineptr = buff;
	if (r == 0)
		return (-1);
	for (i = 0; buff[i] != '\n'; i++)
		;
	buff[i + 1] = '\0';
	return (r);
}
