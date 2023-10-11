#include "main.h"
/**
 * tokenizer - convert input string int an array of tokens
 * @input: input string
 * Return: array of string (command arguments)
 */
char **tokenizer(char *input)
{
	int n = 0, i = 0;
	char *str2, *tok, *del = " \n\t";
	char **cmd;

	if (input == NULL)
		return (NULL);
	str2 = _strcpy(input);
	tok = strtok(str2, del);
	if (tok == NULL)
	{
		free(str2);
		free(input);
		return (NULL);
	}
	while (tok != NULL)
	{
		n++;
		tok = strtok(NULL, del);
	}
	free(str2);
	cmd = malloc(sizeof(char *) * (n + 1));
	if (cmd == NULL)
	{
		free(input);
		return (NULL);
	}
	tok = strtok(input, del);
	while (tok)
	{
		cmd[i] = tok;
		tok = strtok(NULL, del);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}
