#include "simple_shell.h"
/**
 * execution - function that compares our string and execute the command.
 *
 * @tokens: Our array of tokens
 * @env: Our enviorment variables
 *
 * Return: Always return one
 *
 * Description: First our function will compare our token position 0
 * with the built-in (exit & env). If its not a built in he will check
 * for the command and print out the result of the execution.
 */
int execution(char **tokens,  char **env)
{
	int i, status;
	pid_t child_pid;
	char **path_tok, *cmd;
	struct stat rawr;

	path_tok = path(env);
	for (i = 0; path_tok[i]; i++)
	{
		if (strstr(tokens[0], path_tok[i]) != NULL)
			break;
	}
	if (path_tok[i] == NULL)
	{
		for (i = 0; path_tok[i]; i++)
		{
			cmd = _strcat(path_tok[i], tokens[0]);
			if (stat(cmd, &rawr) == 0)
			{
				tokens[0] = cmd;
				break;
			}
		}
	}
	child_pid = fork();
	if (child_pid == -1)
		perror("Child process failed");
	else if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, env) == -1)
		{
			perror("./hsh");
			free(cmd);
			free_array(tokens);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	free_array(path_tok);
	return (1);
}
