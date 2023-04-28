#include "shell.h"

/**
 * bfree - this free a pointer while  NULling the address(s)
 * @ptr: this is the address of the pointer which points to free
 *
 * Return: if freed return 1,  0 if not.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
