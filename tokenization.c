#include "simple_shell.h"
char **tokenization(char *ptr, char *delim)
{
	/* Allocating space for the array */
	char *token = NULL, **tokens = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * _strlen(ptr) + 1);
	token = strtok(ptr, delim);
	while(token)
	{
		/* Allocating space for designated position inside array */
		tokens[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(tokens[i], token);/* Copy the string in token to the array of tokens */
		i++;
		token = NULL; /* Clean the token, before using it again */
		token = strtok(NULL, delim);
	}
	/* Last position in the array equal to NULL */
	tokens[i] = NULL;
	return (tokens);
}
