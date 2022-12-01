#include "simple_shell.h"
/**
 * _strcmp - compare two strings
 * @comparing: source string
 * @compare: string to be compare againt source.
 *
 * Return: 0 if its equal, otherwise is not equal.
 */
int _strcmp(char *comparing, char *compare)
{
	while (*comparing == *compare)
	{
		if (*comparing == '\0')
		{
			return (0);
		}
		comparing++;
		compare++;
	}
	return (*comparing - *compare);
}
