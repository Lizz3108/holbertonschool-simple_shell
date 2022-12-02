#include "simple_shell.h"
/**
 * strduplicate - Duplicates a given string
 * @s: given string
 * Return: Copy of given string
*/
char *_strdup(char *s)
{
	char *ptr;
	int i, len = 0;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);

	ptr = malloc(sizeof(char) * (len + 1));

	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		ptr[i] = s[i];

	ptr[i] = '\0';

	return (ptr);
}
