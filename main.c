#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 *
 * main - Entry point for the hsh simple shell.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	int count = 0;
	(void)argc;

	while (getline(&line, &len, stdin) != -1)
	{
		count++;
		line[strcspn(line, "\n")] = '\0';

		if (access(line, X_OK) == -1)
		{
			fprintf(stderr, "%s: %d: %s: not found\n",
				argv[0], count, line);
		}
	}

	free(line);
	return (0);
}
