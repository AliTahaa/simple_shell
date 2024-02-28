#include "shell.h"
/**
 * is_built_in - check if is built in func
 *
 * @command: the command
 * Return: 1 or 0
 */
int is_built_in(char *command)
{

	char *built_in_arr[] = {
		"exit",
		"env",
		"setenv",
		"cd",
		NULL};

	int i;

	for (i = 0; built_in_arr[i]; i++)
	{
		if (_strcmp(command, built_in_arr[i]) == 0)
			return (1);
	}

	return (0);
}
/**
 * handle_built_in - check and select the func
 *
 * @command: the command
 * @argv: the arguments
 * @status: the status
 * @index: the index
 * Return: nothing
 */
void handle_built_in(char **command, char **argv, int status, int index)
{
	(void)argv;
	(void)index;
	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command, status);

	else if (_strcmp(command[0], "env") == 0)
		print_env(command, status);
}
/**
 * exit_shell - exit the shell
 *
 * @command: the command
 * @status: the status
 * Return: nothing
 */
void exit_shell(char **command, int status)
{
	free_arr(command);
	exit(status);
}
/**
 * print_env - print the environment
 *
 * @command: the command
 * @status: the status
 * Return: nothing
 */
void print_env(char **command, int status)
{

	int i;
	(void)status;

	for (i = 0; enviro[i]; i++)
	{
		write(STDOUT_FILENO, enviro[i], _strlen(enviro[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	free_arr(command);
}
