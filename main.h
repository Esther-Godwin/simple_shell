#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/wait.h>
extern char **environ;

/**
 * struct env_t - Struct of shell environment variables
 * @in_terminal: Specifies if shell in terminal or not
 * @status: The last command status
 * @program_name: The program name
 * @exit_signal: exit signal
 */

typedef struct env_t
{
	int in_terminal;
	int status;
	char *program_name;
	int exit_signal;
} env_t;

int _putchar(char ch);
char **tokenize(char *buffer, env_t *env);
void print_error(env_t *env, char *command);
void init_prog(char *av, env_t *env);
int wait_exit(env_t *env);
int _strlen(char *s);
void execute(env_t *env, char **tokens, char *program_name);

#endif
