#include "main.h"

/**
 * _putchar - Prints a character
 * @c: Character to print
 *
 * Return: Number of character printed
 */
int _putchar(char ch)
{
	return (write(STDOUT_FILENO, &c, 1));
}

/**
 * tokenize - Tokinize user input
 * @buffer: String to tokenize
 * @env: env struct
 *
 * Return: Pointer to tokenized string
 */
char **tokenize(char *buffer, env_t *env)
{
	char *token, **temp;
	int i;

	temp = malloc(sizeof(*temp) * 1024);
	if (!temp)
		env->status = -1;
	token = strtok(buffer, " \t\n");
	for (i = 0; token; i++)
	{
		temp[i] = token;
		token = strtok(NULL, " \t\n");
	}
	temp[i] = NULL;
	return temp;
}

/**
 * _strlen - Calculates the length of a string
 * s: The string to get its length
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int count = 0, i = 0;

	while (s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

/**
 * wait_exit - wait then exit
 * @env: env struct
 *
 * Return: 0 on success
 */
int wait_exit(env_t *env)
{
	int status_code;

	wait(&status_code);
	env->status = WEXITSTATUS(status_code);
	return (env->status);
}
