#include "simple_shell.h"
/**
 * _strcmp - compare two strings
 *
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
			return (0);
		comparing++;
		compare++;
	}
	return (*comparing - *compare);
}

#include "simple_shell.h"
/**
 * _strncmp - Compares two strings with n size
 *
 * @compare: Given String 1
 * @comparing: Given String 2
 * @n: Size to character compare
 *
 * Return: 0 both strings are equals
*/
int _strncmp(char *compare,  char *comparing, size_t n)
{
	while (n && *compare && (*compare == *comparing))
	{
		++compare;
		++comparing;
		--n;
	}

	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)compare - *(unsigned char *)comparing);
}
