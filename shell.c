#include "main.h"

/**
 * main - Creates a command line interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success
*/
int main(int __attribute__((unused)) argc, char **argv)
{
	char *buffer = NULL, **tokens;
	ssize_t read_count = 0, write_count;
	size_t len;
	pid_t pid;
	bool is_interactive;
	env_t env;

	init_prog(argv[0], &env);
	is_interactive = isatty(STDIN_FILENO);
	while (env.in_terminal && read_count != -1)
	{
		if (is_interactive)
		{
			write_count = write(STDOUT_FILENO, "$ ", 2);
			env.in_terminal = 1;
		}
		if (write_count == -1)
			return (1);
		read_count = getline(&buffer, &len, stdin);
		if (read_count == -1)
		{
			if (is_interactive)
				_putchar('\n');
			free(buffer);
			return (1);
			exit(env.status);
		}
		tokens = tokenize(buffer, &env);
		pid = fork();
		if (pid == 0)
		{
			execve(argv[0], tokens, environ);
		}
		else
		{
			env.status = wait_exit(&env);
		}
		free(tokens);
	}
	exit(env.status);
}

