#include "main.h"
/**
 * tokenizer - convert input string int an array of tokens
 * @input: input string
 * Return: array of string (command arguments)
 */
char **tokenizer(char *input)
{
	int n, i = 0;
	char *str = NULL, *str2 = NULL, *tok = NULL, *del = " \n\t";
	char **cmd;

	if (input == NULL)
		return (NULL);
	str = _strcpy(input);
	str2 = _strcpy(input);
	n = tok_num(str2);
	free(input), input = NULL;
	cmd = malloc(sizeof(char *) * (n + 1));
	if (cmd == NULL)
	{
		free(str), str = NULL;
		return (NULL);
	}
	tok = strtok(str, del);
	while (tok)
	{
		if (_strcmp(tok, "#") == 0)
		{
			cmd[i] = NULL;
			free(str), str = NULL;
			return (cmd);
		}
		cmd[i] = _strcpy(tok);
		if (cmd[i] == NULL)
		{
			_free(cmd);
			free(str), str = NULL;
			return (NULL);
		}
		tok = strtok(NULL, del);
		i++;
	}
	cmd[i] = NULL;
	free(str), str = NULL;
	return (cmd);
}
/**
 * tok_num - calculate number of tokens in string
 * @str2: string to be tokenized
 * Return: number of token
 */
int tok_num(char *str2)
{
	int count = 0;
	char *del = " \n\t", *tok = NULL;

	if (str2 == NULL)
	{
		free(str2), str2 = NULL;
		return (0);
	}
	tok = strtok(str2, del);
	if (tok == NULL)
	{
		free(str2), str2 = NULL;
		return (0);
	}
	while (tok)
	{
		count++;
		tok = strtok(NULL, del);
	}
	free(str2), str2 = NULL;
	return (count);
}
