#include "shell.h"

/**
 * _getenv - gets the value of an environment variable
 * @name: name of the variable
 *
 * Return: pointer to the value, or NULL if not found
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t len = strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
			return (&environ[i][len + 1]);
		i++;
	}
	return (NULL);
}

/**
 * get_path - locates the executable file in the PATH
 * @command: the command typed by the user
 *
 * Return: full path of the executable, or NULL if not found
 */
char *get_path(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int cmd_len, dir_len;
	struct stat buffer;

	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &buffer) == 0)
			return (strdup(command));
		return (NULL);
	}

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	cmd_len = strlen(command);
	path_token = strtok(path_copy, ":");

	while (path_token != NULL)
	{
		dir_len = strlen(path_token);
		file_path = malloc(cmd_len + dir_len + 2);
		if (file_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}

		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, command);

		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return (file_path);
		}

		free(file_path);
		path_token = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
