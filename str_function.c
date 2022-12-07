#include "simple_shell.h"
/**
 * _strcpy - Copies the string pointed to by src
 * including the terminating null byte(\0), to the buffer
 * pointer to by dest.
 *
 * @dest: destination
 * @src: source
 *
 * Return: Return the value of the pointer dest
 */
char *_strcpy(char *dest, char *src)
{
	int copy;

	copy = 0;

	while (src[copy] != '\0')
	{
		dest[copy] = src[copy];
		copy++;
	}
	dest[copy] = '\0';

	return (dest);
}

#include "simple_shell.h"
/**
 * _strcat - This function appendes the src to the dest string,
 * overwritingh the termination null byte at the end of dest,
 * and then adds a termination null byte.
 *
 * @dest: original
 * @src: to be added to dest
 *
 * Return: a pointer to the resulting string of dest.
 */
char *_strcat(char *dest, char *src)
{
	int move, original;

	original = 0;
	move = 0;

	while (dest[original] != '\0')
		original++;

	dest[original] = '/';

	original++;

	while (src[move] != '\0')
	{
		dest[original] = src[move];
		original++;
		move++;
	}
	dest[original] = '\0';
	return (dest);
}

#include "simple_shell.h"
/**
 * _strlen - Return the lenght of a string
 *
 * @s: charater pointer
 *
 * Return: the lenght of the string
 */
int _strlen(char *s)
{
	int lenght;

	for (lenght = 0; s[lenght] != '\0'; lenght++)
		;

	return (lenght);
}

#include "simple_shell.h"
/**
 * _strdup - Duplicates a given string
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
