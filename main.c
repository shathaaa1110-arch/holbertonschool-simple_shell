#include "shell.h"

/**
 * print_env - Prints the current environment variables
 */
void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * main - Simple shell main function
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: Always 0 on success, or error status
 */
int main(int ac __attribute__((unused)), char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;
	int status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");

		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			exit(status);
		}

		args = parse_command(line);
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				free(args);
				free(line);
				exit(status);
			}
			else if (strcmp(args[0], "env") == 0)
			{
				print_env();
				status = 0;
			}
			else
			{
				status = execute_command(args, av[0]);
			}
		}
		free(args);
	}
	free(line);
	return (status);
}
