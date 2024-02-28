#include "shell.h"
/**
 * _get_enviro - get the environment
 *
 * @variable: the variable
 * Return: the environment or Null
 */
char *_get_enviro(char *variable)
{
	char *tmp, *key, *value, *env;
	int i;

	for (i = 0; enviro[i]; i++)
	{
		tmp = _strdup(enviro[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
/**
 * _get_path - get the path
 *
 * @command: the command
 * Return: all command or Null
 */
char *_get_path(char *command)
{
	char *path_env, *all_command, *dir;
	int i;
	struct stat st;

	for (i = 0; command[i]; i++)
	{
		if (command[i] == '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			return (NULL);
		}
	}

	path_env = _get_enviro("PATH");
	if (!path_env)
		return (NULL);

	dir = strtok(path_env, ":");
	while (dir)
	{
		all_command = malloc(_strlen(dir) + _strlen(command) + 2);
		if (all_command)
		{
			_strcpy(all_command, dir);
			_strcat(all_command, "/");
			_strcat(all_command, command);
			if (stat(all_command, &st) == 0)
			{
				free(path_env);
				return (all_command);
			}
			free(all_command), all_command = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(path_env);
	return (NULL);
}
