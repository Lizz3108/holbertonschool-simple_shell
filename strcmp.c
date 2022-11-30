#include "simple_shell.h"
/**
 * _strcmp - compare two strings
 * @s1: string one
 * @s2: string two
 * Return: return the value of strings
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
