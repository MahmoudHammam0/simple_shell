#include "main.h"
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
