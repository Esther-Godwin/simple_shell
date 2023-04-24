#include "main.h"

/**
 * execute - runs the command
 * @env: env struct
 * @tokens: Commands to run
 * @program_name: Program name
 */
void execute(env_t *env, char **tokens, char *program_name)
{
	int status = 0;

	status = execve(program_name, tokens, environ);
	if (status == -1)
	{
		print_error(env, tokens[0]);
		exit(1);
	}
	exit(0);
}
