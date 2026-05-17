#include "shell.h"

/**
 * execute_command - Executes a command, handling PATH correctly
 * @args: Array of arguments
 * @program_name: The name of the shell program
 */
void execute_command(char **args, char *program_name)
{
	pid_t child_pid;
	int status;
	char *actual_path;

	if (args[0] == NULL)
		return;

	actual_path = get_path(args[0]);

	if (actual_path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", program_name, args[0]);
		return;
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork Error");
		free(actual_path);
		return;
	}

	if (child_pid == 0)
	{
		if (execve(actual_path, args, environ) == -1)
		{
			perror(program_name);
			free(actual_path);
			exit(1);
		}
	}
	else
	{
		wait(&status);
		free(actual_path);
	}
}
