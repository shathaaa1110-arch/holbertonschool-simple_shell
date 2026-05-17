#include "shell.h"

/**
 * parse_command - splits a string into words
 * @line: the string to split
 *
 * Return: array of pointers to words
 */
char **parse_command(char *line)
{
	int i = 0;
	char **tokens;
	char *token;

	tokens = malloc(64 * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\n");

	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;

	return (tokens);
}
