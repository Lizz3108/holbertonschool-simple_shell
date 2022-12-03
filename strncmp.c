#include "simple_shell.h"
/**
 * strncomparer - Compares two strings with n size
 * @s1: Given String 1
 * @s2: Given String 2
 * @n: Size to character compare
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
	{
		return (0);
	}
	else
	{
		return (*(unsigned char *)compare - *(unsigned char *)comparing);
	}
}
