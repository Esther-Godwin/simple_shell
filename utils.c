#include "main.h"

/**
 * wait_exit - wait and exit.
 * @env: struct of shell vars
 * Return: 0 on sucess.
 */
int wait_exit(env_t *env)
{
	int status;

	wait(&status);
	if (WEXITSTATUS(status) == 127)
		env->count++;
	env->status = WEXITSTATUS(status);
	return (env->status);
}

/**
 * handle_signal - voids a signal and prints prompt.
 * @signal: signal to be ignored.
 * Return: nothing.
 */

void handle_signal(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n$ ", 3);

}

/**
 * handle_eof - handles EOF input
 * @interactive: bool determining interactive mode
 * @line: line to free
 * @env: linked list to free
 */
void handle_eof(bool interactive, char *line, env_t *env)
{
	if (interactive)
		_putchar('\n');
	free_chars(line, env);
	exit(env->status);
}

/**
 * processing - calls pathfinder.
 * @env: struct of shell vars.
 * @args: argument.
 * Return: Nothing.
 */
void processing(env_t *env, char **args)
{
	int fail_check2 = 0;

	fail_check2 = pathfinder(args, env);
	if (fail_check2 == -1)
	{
		error_msg(env, args[0]);
		env->count++;
		exit(127);
	}
	exit(0);
}

/**
 * _putchar - prints one character at a time to the stdout
 * @c: character to be printed
 * Return:character.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
