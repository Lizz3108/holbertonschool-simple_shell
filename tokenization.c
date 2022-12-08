#include "simple_shell.h"
/**
 * tokenization - extract tokens from the getline command
 *
 * @ptr: String of the command line
 * @delim: Delimiter
 *
 * Return: the array of tokens
 *
 * Description: We first allocate space for the array of tokens. We extract
 * our fits token and save it in token. We start a loop that will run while
 * token have something. Inside we allocate space for the posision inside
 * the index. Then we copy the string from token into the index. We clean
 * out token variable and start the process again. After our while our last
 * index is assign as NULL, to mark the end of the array.
 */
char **tokenization(char *ptr, char *delim)
{
	char *token = NULL, **tokens = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 10);
	token = strtok(ptr, delim);

	while (token)
	{
		tokens[i] = malloc(sizeof(char) * _strlen(token) + 1);
		_strcpy(tokens[i], token);
		i++;
		token = NULL;
		token = strtok(NULL, delim);
	}

	tokens[i] = NULL;
	free(token);
	return (tokens);
}
