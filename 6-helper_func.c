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
			break;
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
 * num_to_char - change an int to string
 * @n: number to be converted
 * Return: number string
 */
char *num_to_char(int n)
{
	int len = 0, num = n, i, j;
	char *s;
	char r;

	while (num != 0)
	{
		num /= 10;
		len++;
	}
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	*s = '\0';
	for (i = 0; (n / 10); i++)
	{
		s[i] = (n % 10) + 48;
		n /= 10;
	}
	s[i] = (n % 10) + 48;
	for (j = 0; j < (len / 2); j++)
	{
		r = s[j];
		s[j] = s[len - 1 - j];
		s[len - 1 - j] = r;
	}
	s[j + 1] = '\0';
	return (s);
}
/**
 * print - print string to stdout
 * @s: string to be printed
 * Return: Nothing
 */
void print(char *s)
{
	write(1, s, _strlen(s));
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
