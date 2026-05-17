#ifndef SHELL_H
#define SHELL_H

/**
 * file: shell.h
 * desc: Header file containing declarations for all functions
 *       used in the holbertonschool-simple_shell project.
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

int main(int argc, char *argv[]);
void execute_command(char **args, char *program_name);
char **parse_command(char *line);
char *_getenv(const char *name);
char *get_path(char *command);

#endif /* SHELL_H */
