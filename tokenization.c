#include "simple_shell.h"
char **tokenization(char *ptr, char *delim)
{
	/* Allocating space for the array */
	char *token = NULL, **tokens = malloc(sizeof(char *) * _strlen(ptr));
	int i = 0;

	if (tokens == NULL)
		return (NULL);

	token = strtok(ptr, delim);
	while(token)
	{
		/* Allocating space for designated position inside array */
		tokens[i] = malloc(sizeof(char) * _strlen(token) + 1);
		if (tokens == NULL)
			return (NULL);
		_strcpy(tokens[i], token);
		i++;
		token = NULL;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	return (tokens);
}
