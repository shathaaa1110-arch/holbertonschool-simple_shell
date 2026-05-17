#include "shell.h"

/**
 * execute_command - Executes a command with arguments
 * @args: Array of arguments (e.g., ["ls", "-l", NULL])
 * @program_name: The name of the shell program
 */
void execute_command(char **args, char *program_name)
{
	pid_t child_pid;
	int status;

	if (args[0] == NULL)
		return;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork Error");
		return;
	}

	if (child_pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror(program_name);
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
}
