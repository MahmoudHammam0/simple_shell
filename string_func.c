#include "main.h"
/**
 * _strlen - calculate string length
 * @str: given string
 * Return: length of string excluding null
 */
int _strlen(char *str)
{
	int i, count = 0;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		count++;
	return (count);
}
/**
 * _strcpy - copy a string
 * @str: string to be copied
 * Return: copied string
 */
char *_strcpy(char *str)
{
	char *strdup;
	int len, i;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	strdup = malloc(sizeof(char) * (len + 1));
	if (strdup == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		strdup[i] = str[i];
	strdup[i] = '\0';
	return (strdup);
}

/**
 * _strtok - tokenizes a string
 * @str: input string
 * @delim: delimiter
 *
 * Return: one token at a time
 */
char *_strtok(char *str, const char *delim)
{
	int len = 0, i = 0;
	static char *token;
	char *current_token;

	if (str != NULL)
		token = str;

	if (!token || *token == '\0')
		return (NULL);

	while (*token == delim[0])
		token++;

	while (token[len] != '\0' && token[len] != delim[0])
		len++;

	current_token = malloc(len + 1);

	if (current_token == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		current_token[i] = token[i];

	current_token[i] = '\0';

	token += len;

	token++;
	if (*token != '\0' && *token == delim[0])
	{
		while (*token == delim[0])
			token++;
	}

	return (current_token);
}
