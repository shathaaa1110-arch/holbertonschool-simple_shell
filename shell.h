#ifndef SHELL_H
#define SHELL_H

/**
 * file: shell.h
 * desc: Header file containing declarations for all functions
 *       used in the holbertonschool-simple_shell project.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

int main(int argc, char *argv[]);
void execute_command(char **args, char *program_name);
char **parse_command(char *line);

#endif /* SHELL_H */
