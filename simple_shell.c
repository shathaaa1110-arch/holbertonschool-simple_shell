#include "shell.h"

/**
 * main - Entry point for the simple shell 0.1
 * @argc: The number of arguments passed to the program
 * @argv: An array of strings containing the arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
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

		if (strlen(line) == 0)
			continue;

		args[0] = line;
		args[1] = NULL;

		if (access(line, X_OK) == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				break;
			}
			if (child_pid == 0)
			{
				if (execve(args[0], args, environ) == -1)
				{
					perror(argv[0]);
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
	}
	free(line);
	return (0);
}
