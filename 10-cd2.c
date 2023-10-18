#include "main.h"
/**
 * cd_home - handle cd command without parameters
 * @new_path: new path
 * @curr_path: current path
 * @env: environ change
 * Return: 0 Success
 */
int cd_home(char *new_path, char *curr_path, int *env)
{
	curr_path = getcwd(curr_path, 0);
	new_path = _getenv("HOME");
	if (new_path != NULL)
	{
		chdir(new_path);
		env_update(new_path, curr_path, env);
		return (0);
	}
	else
	{
		free(new_path), new_path = NULL;
		free(curr_path), curr_path = NULL;
		return (0);
	}
	return (0);
}
/**
 * cd_pre - handle cd command with -
 * @new_path: new path
 * @curr_path: current path
 * @env: environ change
 * Return: 0 Success
 */
int cd_pre(char *new_path, char *curr_path, int *env)
{
	char *str = NULL;

	curr_path = getcwd(curr_path, 0);
	new_path = _getenv("OLDPWD");
	if (new_path != NULL)
	{
		chdir(new_path);
		str = getcwd(str, 0);
		write(1, str, _strlen(str));
		write(1, "\n", 1);
		env_update(new_path, curr_path, env);
		free(str), str = NULL;
		return (0);
	}
	else
	{
		free(new_path), new_path = NULL;
		free(curr_path), curr_path = NULL;
		str = getcwd(str, 0);
		write(1, str, _strlen(str));
		write(1, "\n", 1);
		free(str), str = NULL;
		return (0);
	}
	return (0);
}
