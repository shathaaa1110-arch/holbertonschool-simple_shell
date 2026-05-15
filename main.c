#include "shell.h"

/**
 * trim_spaces - Removes leading and trailing spaces from a string
 * @str: The string to be trimmed
 *
 * Return: A pointer to the trimmed string within the original text
 */
char *trim_spaces(char *str)
{
	char *end;

	while (*str == ' ' || *str == '\t')
		str++;

	if (*str == '\0')
		return (str);

	end = str + strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
	{
		*end = '\0';
		end--;
	}

	return (str);
}

/**
 * main - Entry point for the simple shell
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings containing the arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	char *cleaned_line;
	char *command_pure;
	char *line_copy;
	size_t len = 0;
	ssize_t nread;
	pid_t child_pid;
	int status;
	char *args[2];
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		if (nread > 0 && line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		cleaned_line = trim_spaces(line);
		if (strlen(cleaned_line) == 0)
			continue;

		line_copy = strdup(cleaned_line);
		if (line_copy == NULL)
			continue;

		command_pure = strtok(line_copy, " \t");

		if (command_pure != NULL && access(command_pure, X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				free(line_copy);
				break;
			}
			if (child_pid == 0)
			{
				args[0] = cleaned_line;
				args[1] = NULL;

				if (execve(args[0], args, environ) == -1)
				{
					perror(argv[0]);
					free(line_copy);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(&status);
			}
		}
		else
		{
			fprintf(stderr, "%s: No such file or directory\n", argv[0]);
		}
		free(line_copy);
	}
	free(line);
	return (0);
}
