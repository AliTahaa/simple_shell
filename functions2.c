#include "shell.h"
/**
 * free_arr - Frees the memory allocated for an array of strings.
 *
 * @arr: Pointer to an array of character pointers.
 * Return: Nothing.
 */
void free_arr(char **arr)
{
	int i;

	if (!arr)
		return;
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]), arr[i] = NULL;
	}
	free(arr), arr = NULL;
}
/**
 * _itoa - Converts an integer to decimal string.
 *
 * @n: Integer to convert.
 * Return: copy from Buffer.
 */
char *_itoa(int n)
{
	char buffer[20];
	int i = 0;

	if (n == 0)
		buffer[i++] = '0';
	else
	{

		while (n > 0)
		{
			buffer[i++] = (n % 10) + '0';
			n /= 10;
		}
	}

	buffer[i] = '\0';
	rev_string(buffer, i);

	return (_strdup(buffer));
}
/**
 * rev_string - Reverses a null-terminated character string in-place.
 *
 * @str: Pointer to the null-terminated string to reverse.
 * @len: Length of the string (excluding null terminator).
 * Return: Nothing.
 */
void rev_string(char *str, int len)
{

	char tmp;
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}
/**
 * print_error - Prints an error message to standard error.
 *
 * @name: Pointer to string representing name of not found entity.
 * @command: Pointer to string representing attempted command.
 * @index: Integer index of not found item.
 * Return: Nothing.
 */
void print_error(char *name, char *command, int index)
{
	char *indx, message[] = ": not found\n";

	indx = _itoa(index);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, indx, _strlen(indx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, message, _strlen(message));

	free(indx);
}
