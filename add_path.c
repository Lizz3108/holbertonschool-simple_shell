#include "simple_shell.h"
/**
 * add_path - this functions concatenates the path with the cmd
 * @tokens: the cmd the person introduces
 * @path_tok: the path
 * Returns: the path concatenated in position 0 of the array.
 */
char *add_path(char **tokens, char **path_tok)
{
	char *cmd;
	int i = 0;
	struct stat rawr;

	while (path_tok[i] != NULL)
	{
		cmd = _strcat(path_tok[i], tokens[0]);
		if (stat(cmd, &rawr) == 0)
		{
			tokens[0] = cmd;
			break;
		}
		i++;
	}
	return (tokens[0]);
}
