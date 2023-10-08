#include "main.h"
/**
 * main - Entry point
 * Description: simple shell
 * @argc: command line arguments count
 * @argv: array of strings (commandline arguments)
 * Return: 0(Success)
 */
int main(int __attribute__((unused))argc, char **argv)
{
	char *input = NULL;
	char **cmd;
	int stat = 0, g;

	for (g = 1; g > 0; g++)
	{
		input = get_input();
		if (input == NULL)
		{
			if (isatty(0) != 0)
				write(1, "\n", 1);
			return (stat);
		}
		cmd = tokenizer(input);
		if (cmd == NULL)
			continue;
		stat = executioner(cmd, argv, input);
	}
	return (0);
}
