#include "main.h"

/**
 * add_path - adds the path /bin/ at the beginning
 * @str: input string
 *
 * Return: the updated string
 */
char *add_path(char *str)
{
	char *full_path;

	full_path = _strcpy("/bin/");
	strcat(full_path, str);

	free(str);
	str = strdup(full_path);
	if (str == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	return (str);
}


/**
 * executioner - execute commands
 * @cmd: array of strings(command arguments)
 * @argv: array of strings (commandline arguments)
 * @input: input string
 * Return: exit status
 */
int executioner(char **cmd, char **argv, char *input)
{
	pid_t pid;
	int stat, v;

	pid = fork();
	if (pid == 0)
	{
		cmd[0] = add_path(cmd[0]);
		v = execve(cmd[0], cmd, environ);
		if (v < 0)
		{
			perror(argv[0]);
			exit(0);
		}
	}
	else
	{
		waitpid(pid, &stat, 0);
	}
	free(input);
	free(cmd);
	return (WEXITSTATUS(stat));
}
