#include "shell.h"

/**
 * main - Simple shell main function
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: Always 0
 */
int main(int ac __attribute__((unused)), char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(0);
		}

		args = parse_command(line);

		if (args[0] != NULL)
			execute_command(args, av[0]);

		free(args);
	}

	free(line);
	return (0);
}
