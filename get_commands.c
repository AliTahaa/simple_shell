#include "shell.h"
/**
 * read_all - read all the line
 * Return: the line
 */
char *read_all(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t len2;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	len2 = getline(&line, &len, stdin);
	if (len2 == -1)
	{
		free(line), line = NULL;
		return (NULL);
	}

	return (line);
}
/**
 * split_line - split the line to words (tokens)
 *
 * @line: pointer to all the line
 * Return: the command list
 */
char **split_line(char *line)
{
	char *word = NULL;
	char *temp = NULL;
	char **command = NULL;
	int cpt = 0, i = 0;

	if (!line)
		return (NULL);
	temp = _strdup(line);
	word = strtok(temp, DELIMITER);

	if (word == NULL)
	{
		free(line), line = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	while (word)
	{
		cpt++;
		word = strtok(NULL, DELIMITER);
	}
	free(temp), temp = NULL;

	command = malloc(sizeof(char *) * (cpt + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}

	word = strtok(line, DELIMITER);
	while (word)
	{
		command[i] = _strdup(word);
		word = strtok(NULL, DELIMITER);
		i++;
	}
	free(line), line = NULL;
	command[i] = NULL;
	return (command);
}
