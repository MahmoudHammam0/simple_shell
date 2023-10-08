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
