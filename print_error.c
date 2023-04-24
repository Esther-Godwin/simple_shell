#include "main.h"

/**
 * print_error - Prints error message
 * @env: env struct
 * @command: shell command
 */
void print_error(env_t *env, char *command)
{
	write(STDERR_FILENO, env->progname, _strlen(env->program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", _strlen(": not found\n"));
}
