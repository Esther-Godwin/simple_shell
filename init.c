#include "main.h"

/**
 * handle_signal - voids a signal and prints prompt.
 * @signal: signal to be ignored.
 */

void handle_signal(int __attribute__((unused)) signal)
{
	write(STDOUT_FILENO, "\n$ ", 3);

}

/**
 * init_env - Initialize shell env variables
 * @env: env struct
 * @program_name: Program name
 *
 * Return: env struct with initialized variables
 */
env_t *init_env(env_t *env, char *program_name)
{
	env->in_terminal = 1;
	env->status = 0;
	env->program_name = program_name;

	signal(SIGINT, handle_signal);

	return (env);
}

/**
 * init_prog - Initialise the prgram
 * @program_name: Name of the program
 * @env: env struct
 */
void init_prog(char *program_name, env_t *env)
{
	init_env(env, program_name);
}

