#include "shell.h"
/**
 * _run - execute the command
 *
 * @command: the command
 * @argv: the arguments
 * @index: the index
 * Return: exit status
 */
int _run(char **command, char **argv, int index)
{
	char *all_command;
	pid_t child;
	int status;

	all_command = _get_path(command[0]);
	if (all_command == 0)
	{
		print_error(argv[0], command[0], index);
		free_arr(command);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(all_command, command, environ) == -1)
		{
			free(all_command), all_command = NULL;
			free_arr(command);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free_arr(command);
		free(all_command), all_command = NULL;
	}
	return (WEXITSTATUS(status));
}
