#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int execute_command(char **args, char *program_name);
char **parse_command(char *line);
char *_getenv(const char *name);
char *get_path(char *command);

#endif /* SHELL_H */
