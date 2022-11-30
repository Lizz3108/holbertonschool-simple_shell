#include "simple_shell.h"
char **tokenization(char *ptr, char *delim)
{
	/* Allocating space for the array */
	char *token = NULL, **tokens = malloc(sizeof(char *) * _strlen(ptr));
	int i = 0;

	/* Handle malloc allocation */
	if (tokens == NULL)
		return (NULL);

	token = strtok(ptr, delim);
	while(token)
	{
		/* Allocating space for designated position inside array */
		tokens[i] = malloc(sizeof(char) * _strlen(token) + 1);

		/* Handle malloc allocation */
		if (tokens == NULL)
			return (NULL);

		_strcpy(tokens[i], token); /* Copy the string in token to the array of tokens */
		i++;
		token = NULL; /* Clean the token, before using it again */
		token = strtok(NULL, delim);
	}
	/* Last position in the array equal to NULL */
	tokens[i] = NULL;
	return (tokens);
}
