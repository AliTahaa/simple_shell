#include "shell.h"
/**
 * main - Entry point
 *
 * @ac: ac
 * @argv: the arguments
 * Return: Always 0
 */
int main(int ac, char **argv)
{

	char *line = NULL;
	char **command = NULL;
	int status = 0, index = 0;
	(void)ac;

	while (1)
	{

		line = read_all();

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		index++;

		command = split_line(line);
		if (!command)
			continue;

		if (is_built_in(command[0]))
			handle_built_in(command, argv, status, index);
		else
			status = _run(command, argv, index);
	}
}
