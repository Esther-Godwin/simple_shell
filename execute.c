#include "main.h"

/**
 * execute - runs the command
 * @env: env struct
 * @tokens: Commands to run
 */
void execute(env_t *env, char **tokens)
{
	int status = 0;

	status = execve(_strdup(tokens[0]), tokens, environ);
	if (status == -1)
	{
		print_error(env, tokens[0]);
		exit(1);
	}
	exit(0);
}
